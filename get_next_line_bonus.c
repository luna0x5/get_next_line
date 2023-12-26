/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit < hmoukit@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:14:42 by hmoukit           #+#    #+#             */
/*   Updated: 2023/12/26 19:02:32 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*s;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
	{
		s2 = ft_strdup(s1);
		return (free(s1), s2);
	}
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s = malloc(s1len + s2len + 1);
	if (s == NULL)
		return (free(s1), s1 = NULL, NULL);
	ft_strcpy(s, s1);
	ft_strcpy(s + s1len, s2);
	if (s1)
		free(s1);
	return (s);
}

char	*read_line(int fd)
{
	ssize_t	count;
	char	*all_buffer;
	char	*buffer;

	count = 1;
	all_buffer = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
			return (free(buffer), buffer = NULL, NULL);
		buffer[count] = '\0';
		if (count == 0)
			break ;
		all_buffer = ft_strjoin(all_buffer, buffer);
		if (!all_buffer)
			return (free(buffer), buffer = NULL, NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), buffer = NULL, all_buffer);
}

char	*rest_buffer(char *buffer)
{
	char	*srch;

	if (!buffer)
		return (NULL);
	srch = ft_strchr(buffer, '\n');
	if (!srch)
		return (free(buffer), buffer = NULL, NULL);
	if (*(srch + 1) == '\0')
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_strcpy(buffer, srch + 1);
	if (buffer[0] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	return (buffer);
}

char	*make_line(char **buffer)
{
	char	*line;
	char	*tmp;

	line = NULL;
	if (!*buffer || !buffer)
		return (NULL);
	tmp = ft_strchr(*buffer, '\n');
	if (!tmp)
	{
		line = ft_strdup(*buffer);
		return (free(*buffer), *buffer = NULL, line);
	}
	if (*(tmp + 1) == '\0')
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
	}
	else
	{
		line = ft_strndup(*buffer, tmp - *buffer + 1);
		if (!line)
			return (free(*buffer), *buffer = NULL, NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;
	char		*temp;

	line = NULL;
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer[fd])
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	temp = read_line(fd);
	buffer[fd] = ft_strjoin(buffer[fd], temp);
	if (!buffer[fd])
		return (free(temp), temp = NULL, NULL);
	line = make_line(&buffer[fd]);
	buffer[fd] = rest_buffer(buffer[fd]);
	return (free(temp), temp = NULL, line);
}
