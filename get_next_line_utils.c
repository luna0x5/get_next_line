/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit < hmoukit@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:40:01 by hmoukit           #+#    #+#             */
/*   Updated: 2023/12/16 16:30:47 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;
	size_t	i;

	len = ft_strlen((char *)s1);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	if (dst == NULL && (src == NULL || dst == NULL))
		return (NULL);
	if (src == NULL)
		return (dst);
	while (dst[i] && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


char	*ft_strchr(const char *s, int c)
{
	char	n;
	char	*s1;
	int		i;

	n = (char)c;
	s1 = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s1[i] == n)
			return (&s1[i]);
		i++;
	}
	if (n == '\0')
		return (&s1[i]);
	return (NULL);
}
#include <string.h>
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*s;

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
