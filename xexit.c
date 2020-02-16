/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xexit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:31:20 by abiari            #+#    #+#             */
/*   Updated: 2020/02/14 16:11:30 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern void		*g_rtn;

void	*ftft(void)
{
	void	*tmp;

	tmp = g_rtn;
	g_rtn = NULL;
	return (tmp);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	xerror(int x)
{
	x == 1 ? perror("") : 0;
	x == 2 ? perror("") : 0;
	x == 3 ? perror("") : 0;
	x == 4 ? perror("") : 0;
	x == 5 ? perror("") : 0;
	x == 6 ? perror("") : 0;
}

void	*xexit(int x)
{
	xflush();
	xerror(x);
	exit(x ? 1 : 0);
	return ((void*)0);
}
