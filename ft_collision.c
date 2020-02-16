/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:04:31 by abiari            #+#    #+#             */
/*   Updated: 2020/02/15 18:51:19 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		has_sp(float x, float y)
{
	int xtemp;
	int ytemp;

	xtemp = (int)floor(x / TILE_SIZE);
	ytemp = (int)floor(y / TILE_SIZE);
	return (g_game_data.map.map[xtemp +
			(ytemp * g_game_data.map.columns)] == '2');
}

int		has_wall(float x, float y)
{
	int xtemp;
	int ytemp;

	xtemp = (int)(x / TILE_SIZE);
	ytemp = (int)(y / TILE_SIZE);
	return (g_game_data.map.map[xtemp +
			(ytemp * g_game_data.map.columns)] == '1');
}
