/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:59:31 by abiari            #+#    #+#             */
/*   Updated: 2020/02/01 12:40:22 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char*)s;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (*str == c)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
