/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:00:51 by abiari            #+#    #+#             */
/*   Updated: 2020/02/15 21:17:36 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	t_link	*g_x;
void			*g_rtn;

void	*xmalloc(size_t bytes)
{
	t_link	*tmp;

	tmp = g_x;
	if (!(g_rtn = malloc(bytes)))
		return (NULL);
	if (!g_x)
	{
		if (!(g_x = malloc(sizeof(t_link))))
			return (xexit(1));
		g_x->addr = (size_t)g_rtn;
		g_x->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = malloc(sizeof(t_link))))
			return (xexit(1));
		tmp = tmp->next;
		tmp->addr = (size_t)g_rtn;
		tmp->next = NULL;
	}
	return (ftft());
}

int		xbrowse(void *adr)
{
	t_link	*tmp;
	t_link	*back;

	tmp = g_x;
	while (tmp && tmp->addr != (size_t)adr && (back = tmp))
		tmp = tmp->next;
	if (tmp && ((back->next = tmp->next) != NULL + 1))
	{
		free((void *)tmp->addr);
		free(tmp);
		return (0);
	}
	return (1);
}

void	xfree(void *adr)
{
	t_link	*tmp;

	if (g_x && (tmp = g_x))
	{
		if (tmp->addr == (size_t)adr)
		{
			free((void *)tmp->addr);
			g_x = tmp->next;
			free(tmp);
		}
		else
		{
			if (xbrowse(adr))
			{
				ft_putstr("Non user allocated pointer was being freed!\n");
				free(adr);
				return ;
			}
		}
	}
	else
	{
		ft_putstr("Non user allocated pointer was being freed!\n");
		free(adr);
	}
}

void	xflush(void)
{
	t_link	*tmp;

	tmp = g_x;
	free(g_rtn);
	while (tmp)
	{
		free((void *)tmp->addr);
		g_x = tmp->next;
		free(tmp);
		tmp = g_x;
	}
}

/*
** 0: errno (system error)
** 1:
** 2:
** 3:
*/
