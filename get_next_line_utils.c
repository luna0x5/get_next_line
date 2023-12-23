/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoukit < hmoukit@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:18:45 by hmoukit           #+#    #+#             */
/*   Updated: 2023/12/23 06:37:00 by hmoukit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;
	size_t	i;

	len = ft_strlen(s1);
	dst = malloc(len + 1);
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
	while(src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while(src[i] && i < len)
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

char    *ft_strjoin(char *s1, char *s2)
{
    size_t    s1len;
    size_t    s2len;
    char    *s;

    if (s1 == NULL && s2 == NULL)
        return (NULL);
    if (s1 == NULL)
    {
		s1 = ft_strdup(s2);
		return (s1);
	}
    if (s2 == NULL)
	{
		s2 = ft_strdup(s1);
		return (s2);
	}
    s1len = ft_strlen(s1);
    s2len = ft_strlen(s2);
    s = malloc(s1len + s2len + 1);
    if (s == NULL)
        return (NULL);
    ft_strcpy(s, s1);
    ft_strcpy(s + s1len, s2);
    return (free(s1),s);
}
