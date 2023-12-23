/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit < hmoukit@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:19:14 by hmoukit           #+#    #+#             */
/*   Updated: 2023/12/23 08:16:24 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char  *new_buffer(char *buffer)
{
	char *new_buffer;
	int i;
	int j;

	i = 0;
	j = 0;
	if(!buffer)
		return (NULL);
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if(buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new_buffer)
		return (free(buffer), NULL);
	i++;
	while(buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}
// /n /n /n
char *make_line(char *buffer)
{
	char *line;
	int i;

	i = 0;
	if (!(*buffer) || !(*buffer))
		return (NULL);
	while(buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if(buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if(!line)
		return (free(buffer), NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *ft_buffer(char *buffer,int fd)
{
	int read_b;
	char *buffer_all;

	read_b = 1;
	buffer_all = malloc(BUFFER_SIZE + 1);
	if (!buffer_all)
		return (free(buffer), NULL);
	while(ft_strchr(buffer_all, '\n') == NULL  && read_b)
	{
		read_b = read(fd, buffer_all, BUFFER_SIZE);
		if (read_b == -1)
			return (free(buffer_all) ,NULL);
		buffer_all[read_b] = '\0';
		char *tmp = buffer;
		buffer = ft_strjoin(tmp, buffer_all);
	}
	free(buffer_all);
	return (buffer);
}
char *get_next_line(int fd)
{
	static char *buffer;
	char *line;
	
	if (!buffer)
		buffer = ft_strdup("");
	if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
		return (free(buffer), buffer = NULL , NULL);
	buffer = ft_buffer(buffer, fd);
	if(!buffer)
		return (0);
	line = make_line(buffer);
	buffer = new_buffer(buffer);	
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
int main()
{
	// char *s = NULL;
	int fd = open("test1.txt", O_RDONLY);
	// char *str = ft_buffer(s,fd);
	
	// printf("%s\n", str);
	// system("leaks a.out");
	// // int i = 0;
	char *str;
	str = get_next_line(fd);
	int i = 1;
	while (str)
	{
		printf("%d:=> %s", i, str);
		str = get_next_line(fd);
		i++;
	}
	// printf("%s", str);
	// str = ft_get_next_line(fd);
	// printf("%s", str);
	// str = ft_get_next_line(fd);
	// printf("%s", str);
	// exit(0);
	// str = ft_get_next_line(fd);
	// printf("%s\n", str);
	
}



































// char    *get_next_line(int fd)
// {
//     static char    *saved;
//     char    *tmp;
//     char    *line = NULL;
//     char    *res;
//     char    *newline_pos;

//     if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE <= 0)
//     {
//         if (saved)
// 		{
//             free(saved);
//             saved = NULL;
//         }
//         return (0);
//     }
//     if (saved)
//     {
//         res = ft_strchr(saved, '\n');
//         if (res)
//         {
//             size_t j = res - saved + 1;
//             char *s = malloc(ft_strlen(saved) - j + 2);
//             if (s == NULL)
//                 return (NULL);
//             ft_strncpy(s, saved, j);
//             saved = res + 1;
//             return (s);
//         }
//         else
//         {
//             line = ft_strjoin(line, saved);
//             if (saved) {
//                 free(saved);
//                 saved = NULL;
//             }
//         }
//     }
//     int count = 0;
//     char *buffer = malloc((size_t)(BUFFER_SIZE + 1));
//     if (!buffer)
//         return (NULL);
//     while ((count = read(fd, buffer, BUFFER_SIZE)) > 0)
//     {	
//         buffer[count] = '\0';
//         tmp = malloc(count + 1);
//         if (!tmp)
//             return (NULL);
//         newline_pos = ft_strchr(buffer, '\n'); //
//         if (!newline_pos) //
//         {
//             ft_strcpy(tmp, buffer); //
//             line = ft_strjoin(line, tmp); // 
//             if (tmp) {
//                 free(tmp);
//                 tmp = NULL;
//             }
//         }
//         else
//         {
//             ft_strncpy(tmp, buffer, newline_pos - buffer + 1);
//             tmp[newline_pos - buffer + 1] = '\0';
//             if (*(newline_pos + 1) != '\0')
//                 saved = ft_strdup(newline_pos + 1);
//             line = ft_strjoin(line, tmp);//
//             if (tmp) {
//                 free(tmp);
//                 tmp = NULL;
//             }
//             return(free(buffer), line);
//         }
//     }
//     if (read(fd, buffer, BUFFER_SIZE) < 0)
//         return (free(buffer), line);
//     return (free(buffer), line);
// }
//  int main()
//  {
	
//  }
// void	f(void)
// {
// 	system("leaks a.out");
// }