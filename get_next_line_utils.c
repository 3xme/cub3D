/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 09:44:12 by abiari            #+#    #+#             */
/*   Updated: 2020/01/11 19:28:06 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	size_t	s1len;
	size_t	s2len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (s1len + s2len) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		len = 0;
	new = (char *)malloc((size_t)(len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (len--)
	{
		new[i] = *(s + start);
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strdup(const char *str)
{
	char	*new;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
