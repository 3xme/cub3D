/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:57:39 by abiari            #+#    #+#             */
/*   Updated: 2020/02/15 23:14:14 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_p(char *map, int *p)
{
	int i;
	int j;

	i = 0;
	while (i < g_game_data.map.rows)
	{
		j = 0;
		while (j < g_game_data.map.columns)
		{
			if (ft_strchr("NWES", map[j +
				(i * g_game_data.map.columns)]) != NULL)
				(*p)++;
			j++;
		}
		i++;
	}
}

int		check_all(char *map)
{
	int i;
	int j;

	i = 0;
	while (i < g_game_data.map.rows)
	{
		j = 0;
		while (j < g_game_data.map.columns)
		{
			if (ft_strchr("NWES012", map[j +
				(i * g_game_data.map.columns)]) == NULL)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
