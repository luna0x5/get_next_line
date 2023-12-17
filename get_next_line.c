/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit < hmoukit@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:40:23 by hmoukit           #+#    #+#             */
/*   Updated: 2023/12/17 16:25:35 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*savedchar;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	char		*newline_pos;
	char		*s;
	int			read_ret;

	line = NULL;
	tmp = malloc(BUFFER_SIZE + 1);
	if (tmp == NULL)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	if (savedchar != NULL)
	{
		line = ft_strjoin(line, savedchar);
		savedchar = NULL;
	}
	while ((read_ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_ret] = '\0';
		newline_pos = ft_strchr(buffer, '\n');
		if (!newline_pos)
		{
			ft_strcpy(tmp, buffer);
			if (line == NULL)
				line = ft_strdup(tmp);
			else
			{
				s = ft_strjoin(line, tmp);
				free(line);
				line = s;
			}
		}
		else
		{
			ft_strncpy(tmp, buffer, newline_pos - buffer);
			tmp[newline_pos - buffer] = '\0';
			savedchar = ft_strdup(newline_pos + 1);
			if (line == NULL)
				line = ft_strdup(tmp);
			else
			{
				s = ft_strjoin(line, tmp);
				free(line);
				line = s;
			}
			free(tmp);
			return (line);
		}
	}
	free(tmp);
	if (read_ret == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
#include <stdio.h>
#include <fcntl.h>
int main()
{
    int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
    write(fd, "Hello this is a test\nI write into this file using write\nand this is the third line\nand this is the fourth", 105);
    lseek(fd, 0, SEEK_SET);
    char *s = get_next_line(fd);
	char *ss = get_next_line(fd);
	char *sss = get_next_line(fd);
	char *ssss = get_next_line(fd);
    printf("%s\n", s);
	printf("%s\n", ss);
	printf("%s\n", sss);
	printf("%s\n", ssss);
    free(s);
    close(fd);
}