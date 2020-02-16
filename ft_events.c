/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:05:14 by abiari            #+#    #+#             */
/*   Updated: 2020/02/16 22:44:54 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		destroy_window(void)
{
	mlx_destroy_window(g_mlx_ptr, g_win_ptr);
	exit(0);
	return (0);
}

int		key_pressed(int key)
{
	if (key == 123)
		g_player.turn_direction = -1;
	if (key == 0)
		g_player.pov_direction = -1;
	if (key == 2)
		g_player.pov_direction = 1;
	if (key == 124)
		g_player.turn_direction = 1;
	if (key == 1 || key == 125)
		g_player.walk_direction = 1;
	if (key == 13 || key == 126)
		g_player.walk_direction = -1;
	if (key == 53)
		destroy_window();
	return (0);
}

int		key_released(int key)
{
	if (key == 123 || key == 124)
		g_player.turn_direction = 0;
	if (key == 1 || key == 13 || key == 126 || key == 125)
		g_player.walk_direction = 0;
	if (key == 0 || key == 2)
		g_player.pov_direction = 0;
	return (0);
}
