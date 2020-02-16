/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:56:23 by abiari            #+#    #+#             */
/*   Updated: 2020/02/14 21:45:14 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sp_pos(void)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < g_game_data.map.rows)
	{
		j = 0;
		while (j < g_game_data.map.columns)
		{
			if (g_game_data.map.map[j + (i * g_game_data.map.columns)] == '2')
			{
				g_sp[k].x = j * TILE_SIZE + TILE_SIZE / 2;
				g_sp[k].y = i * TILE_SIZE + TILE_SIZE / 2;
				g_num_sp++;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	update_sp_d(void)
{
	int		i;
	int		j;
	t_sp	ech;

	i = -1;
	while (++i < g_num_sp)
		g_sp[i].distance = dist(g_sp[i].x, g_player.x, g_sp[i].y, g_player.y);
	i = 0;
	while (i < g_num_sp)
	{
		j = 0;
		while (j < g_num_sp - i)
		{
			if (g_sp[j].distance < g_sp[j + 1].distance)
			{
				ech = g_sp[j];
				g_sp[j] = g_sp[j + 1];
				g_sp[j + 1] = ech;
			}
			j++;
		}
		i++;
	}
}

void	render_sp(int x, int y, int sp_size, int k)
{
	int colors;
	int i;
	int j;
	int x_s;
	int y_s;

	init_sprite(k, &x_s, &y_s);
	i = -1;
	while (++i < sp_size)
	{
		if (x + i < 0 || x + i > g_game_data.res.width)
			continue;
		if (g_sp[k].distance >= g_rays[x + i].distance)
			continue;
		j = -1;
		while (++j < sp_size)
		{
			colors = g_sp[k].data[x_s * (j * y_s / sp_size) +
								(i * x_s / sp_size)];
			if (colors != 0)
				if (((x + i) >= 0 && (x + i) < g_game_data.res.width) &&
					((y + j) >= 0 && (y + j) < g_game_data.res.height))
					mlx_img_mod(x + i, y + j, colors);
		}
	}
}

void	init_sprite(int k, int *x_s, int *y_s)
{
	int a;

	g_sp[k].ptr = mlx_xpm_file_to_image(g_mlx_ptr,
					g_game_data.paths.s, x_s, y_s);
	if (g_sp[k].ptr == NULL)
	{
		write(2, "error", 5);
		exit(0);
	}
	g_sp[k].data = (int *)mlx_get_data_addr(g_sp[k].ptr, &a, &a, &a);
}

void	sprites(void)
{
	float	sp_angle;
	float	sp_size;
	float	x;
	float	y;
	int		k;

	k = -1;
	while (++k < g_num_sp)
	{
		sp_angle = atan2(g_sp[k].y - g_player.y, g_sp[k].x - g_player.x);
		while (sp_angle - (g_player.rotation_angle * RAD) > M_PI)
			sp_angle -= 2 * M_PI;
		while (sp_angle - (g_player.rotation_angle * RAD) < -M_PI)
			sp_angle += 2 * M_PI;
		if (g_game_data.res.height > g_game_data.res.width)
			sp_size = (g_game_data.res.height / g_sp[k].distance) * TILE_SIZE;
		else
			sp_size = (g_game_data.res.width / g_sp[k].distance) * TILE_SIZE;
		y = g_game_data.res.height / 2 - sp_size / 2;
		x = (sp_angle - (g_player.rotation_angle * RAD)) *
				g_game_data.res.width / (FOV_ANGLE * RAD) +
			(g_game_data.res.width / 2 - sp_size / 2);
		render_sp(x, y, sp_size, k);
	}
}
