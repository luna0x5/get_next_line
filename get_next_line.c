/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit < hmoukit@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:40:23 by hmoukit           #+#    #+#             */
/*   Updated: 2023/12/16 17:51:21 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*line;
	char		*new_line;
	char		*tmp;
	char		*pos;
	size_t		i;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	tmp = malloc(BUFFER_SIZE + 1);
	if (tmp == NULL)
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		i = 0;
		pos = ft_strchr(buffer, '\n');
		if (pos != NULL)
		{
			*(pos + 1) = '\0';
			while (buffer[i] && buffer[i] != '\n')
			{
				tmp[i] = buffer[i];
				i++;
			}
			tmp[i] = '\0';
		}
		else
			ft_strcpy(tmp, buffer);
		if (line == NULL)
		{
			line = ft_strdup(tmp);
			// free(tmp);
		}
		else
		{
			new_line = ft_strjoin(line, tmp);
			free(line);
			// free(tmp);
			line = new_line;
		}
		if (ft_strchr(buffer, '\n'))
            break ;
	}
	if (line && line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	return (line);

	// while (read(fd, buffer, BUFFER_SIZE) > 0)
	// {
	// 	i = 0;
	// 	buffer[BUFFER_SIZE] = '\0';
	// 	while (buffer[i] && buffer[i] != '\n')
	// 	{
	// 		tmp[i] = buffer[i];
	// 		i++;
	// 	}
	// 	tmp[i] = '\0';
	// 	if (line == NULL)
	// 	{
	// 		line = ft_strdup(tmp);
	// 		// free(tmp);
	// 	}
	// 	else
	// 	{
	// 		new_line = ft_strjoin(line, tmp);
	// 		free(line);
	// 		// free(tmp);
	// 		line = new_line;
	// 	}
	// 	if (ft_strchr(buffer, '\n'))
    //         break ;
	// }
}
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_CREAT | O_RDWR, 0777);
	write(fd, "Hello this is a test\nI write into this file using write\nand this is the third line\nand this is the fourth", 105);
	lseek(fd, 0, SEEK_SET);
	char *s = get_next_line(fd);
	printf("%s\n", s);
	free(s);
	while (s != NULL)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s); 
	}
	close(fd);
}
