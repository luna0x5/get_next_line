/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit < hmoukit@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:19:14 by hmoukit           #+#    #+#             */
/*   Updated: 2023/12/20 18:40:29 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
char    *ft_strjoin(char *s1, char *s2)
{
    size_t    s1len;
    size_t    s2len;
    char    *s;
    if (s1 == NULL && s2 == NULL)
        return (NULL);
    if (s1 == NULL)
        return (strdup(s2));
    if (s2 == NULL)
        return (strdup(s1));
    s1len = strlen(s1);
    s2len = strlen(s2);
    s = (char *)malloc((s1len + s2len + 1) * (sizeof(char)));
    if (s == NULL)
        return (NULL);
    strcpy(s, s1);
    strcpy(s + s1len, s2);
    return (s);
}
char    *get_next_line(int fd)
{
    char    *res;
    char    *line = NULL;
    char    *tmp;
    static char    *saved = NULL;
    char    *newline_pos;
    if (saved != NULL)
    {
        res = strchr(saved, '\n');
        if (res)
        {
            size_t j = res - saved + 1;
            char *s = malloc(strlen(saved) - j + 2);
            if (s == NULL)
                return (NULL);
			strncpy(s, saved, j);
            saved = res + 1;
            return (s);
        }
        else
        {
            line = ft_strjoin(line, saved);
            saved = NULL;
			free(saved);
        }
    }
    char *buffer = malloc((size_t)(BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
    int count;
    while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[count] = '\0';
    	tmp = malloc(BUFFER_SIZE + 1);
    	if (!tmp)
        	return (NULL);
        newline_pos = strchr(buffer, '\n');
        if (!newline_pos)
        {
            strcpy(tmp, buffer);
            line = ft_strjoin(line, tmp);
			free(tmp);
        }
        else
        {
            strncpy(tmp, buffer, newline_pos - buffer + 1);
            tmp[newline_pos - buffer + 1] = '\0';
            if (*(newline_pos + 1) != '\0')
                saved = strdup(newline_pos + 1);
            else
			{
				free(saved);
                saved = NULL;
			}
            line = ft_strjoin(line, tmp);
			free(tmp);
            return(line);
        }
    }
	free(buffer);
    return (line);
}
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int i = 1;
    int fd = open("test1.txt", O_CREAT | O_RDWR, 0777);
	char *line;
	line = get_next_line(fd);
	while (line)
	{

    	printf("%d:==>%s", i, line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
    close(fd);
}