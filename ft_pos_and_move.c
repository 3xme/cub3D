/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_and_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:09:53 by abiari            #+#    #+#             */
/*   Updated: 2020/02/15 20:03:41 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_angle(int i, int j)
{
	if (g_game_data.map.map[j + (i * g_game_data.map.columns)] == 'N')
		g_player.rotation_angle = 270;
	if (g_game_data.map.map[j + (i * g_game_data.map.columns)] == 'S')
		g_player.rotation_angle = 90;
	if (g_game_data.map.map[j + (i * g_game_data.map.columns)] == 'W')
		g_player.rotation_angle = 180;
	if (g_game_data.map.map[j + (i * g_game_data.map.columns)] == 'E')
		g_player.rotation_angle = 0;
}

void	player_pos(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_game_data.map.rows)
	{
		j = 0;
		while (j < g_game_data.map.columns)
		{
			if (ft_strchr("NWES", g_game_data.map.map[j +
			(i * g_game_data.map.columns)]))
			{
				g_player.x = j * TILE_SIZE + TILE_SIZE / 2;
				g_player.y = i * TILE_SIZE + TILE_SIZE / 2;
				set_angle(i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_y(float new_x, float new_y)
{
	new_x = cos(g_player.rotation_angle * RAD) * 10;
	new_y = sin(g_player.rotation_angle * RAD) * 10;
	if (g_player.walk_direction == 1)
	{
		if (!has_wall(g_player.x - (new_x * 4), g_player.y - (new_y * 4)) &&
			!has_sp(g_player.x - (new_x * 4), g_player.y - (new_y * 4)))
		{
			g_player.x -= new_x;
			g_player.y -= new_y;
		}
	}
	else if (g_player.walk_direction == -1)
	{
		if (!has_wall(g_player.x + (new_x * 4), g_player.y + (new_y * 4)) &&
			!has_sp(g_player.x + (new_x * 4), g_player.y + (new_y * 4)))
		{
			g_player.x += new_x;
			g_player.y += new_y;
		}
	}
}

void	move_x(float new_x, float new_y)
{
	if (g_player.pov_direction == 1 || g_player.pov_direction == -1)
	{
		new_x = cos((g_player.rotation_angle + 90) * RAD) * 10;
		new_y = sin((g_player.rotation_angle + 90) * RAD) * 10;
		if (!has_wall(g_player.x - (new_x * 4), g_player.y - (new_y * 4)) &&
			!has_sp(g_player.x - (new_x * 4), g_player.y - (new_y * 4)) &&
			g_player.pov_direction == -1)
		{
			g_player.x -= new_x;
			g_player.y -= new_y;
		}
		else if (!has_wall(g_player.x + (new_x * 4),
				g_player.y + (new_y * 4)) &&
				!has_sp(g_player.x + (new_x * 4), g_player.y + (new_y * 4)) &&
				g_player.pov_direction == 1)
		{
			g_player.x += new_x;
			g_player.y += new_y;
		}
	}
}
