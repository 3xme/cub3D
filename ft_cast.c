/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:30:52 by abiari            #+#    #+#             */
/*   Updated: 2020/02/15 20:18:30 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, 360);
	if (angle < 0)
		angle = 360 + angle;
	return (angle);
}

void	init_v_data(float ray_angle)
{
	g_cast_data.v_ray_data.foundvertwallhit = 0;
	g_cast_data.v_ray_data.vertwallhitx = 0;
	g_cast_data.v_ray_data.vertwallhity = 0;
	g_cast_data.v_ray_data.vertwallcontent = 0;
	g_cast_data.xvintercept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	g_cast_data.xvintercept += g_cast_data.rayright ? TILE_SIZE : 0;
	g_cast_data.yvintercept = g_player.y -
	((g_player.x - g_cast_data.xvintercept) * tan(ray_angle * RAD));
	g_cast_data.xstep = TILE_SIZE;
	g_cast_data.xstep *= g_cast_data.rayleft ? -1 : 1;
	g_cast_data.ystep = g_cast_data.xstep * tan(ray_angle * RAD);
	g_cast_data.v_ray_data.nextverttouchx = g_cast_data.xvintercept;
	g_cast_data.v_ray_data.nextverttouchy = g_cast_data.yvintercept;
}

void	set_v(void)
{
	g_cast_data.v_ray_data.vertwallhitx =
	g_cast_data.v_ray_data.nextverttouchx;
	g_cast_data.v_ray_data.vertwallhity =
	g_cast_data.v_ray_data.nextverttouchy;
	g_cast_data.v_ray_data.vertwallcontent =
	g_game_data.map.map[((int)(g_cast_data.h_ray_data.ytocheck /
	TILE_SIZE) * g_game_data.map.columns) +
	(int)(g_cast_data.h_ray_data.xtocheck / TILE_SIZE)];
	g_cast_data.v_ray_data.foundvertwallhit = 1;
}

void	v_ray_inter(float ray_angle)
{
	int check;

	init_v_data(ray_angle);
	check = g_cast_data.rayright ? 0 : -1;
	while (g_cast_data.v_ray_data.nextverttouchx >= 0 &&
	g_cast_data.v_ray_data.nextverttouchx < g_game_data.map.columns *
	TILE_SIZE && g_cast_data.v_ray_data.nextverttouchy >= 0 &&
	g_cast_data.v_ray_data.nextverttouchy < g_game_data.map.rows * TILE_SIZE)
	{
		g_cast_data.v_ray_data.xtocheck =
		g_cast_data.v_ray_data.nextverttouchx;
		g_cast_data.v_ray_data.ytocheck =
		g_cast_data.v_ray_data.nextverttouchy;
		if (has_wall(g_cast_data.v_ray_data.xtocheck +
		check, g_cast_data.v_ray_data.ytocheck))
		{
			set_v();
			break ;
		}
		else
		{
			g_cast_data.v_ray_data.nextverttouchx += g_cast_data.xstep;
			g_cast_data.v_ray_data.nextverttouchy += g_cast_data.ystep;
		}
	}
}

void	cast_ray(float ray_angle, int i)
{
	ray_angle = normalize_angle(ray_angle);
	g_cast_data.raydown = (ray_angle > 0 && ray_angle < 180);
	g_cast_data.rayup = !g_cast_data.raydown;
	g_cast_data.rayleft = (ray_angle > 90 && ray_angle < 270);
	g_cast_data.rayright = !g_cast_data.rayleft;
	h_ray_inter(ray_angle);
	v_ray_inter(ray_angle);
	affect_distance();
	if (g_cast_data.v_ray_data.verthitdistance <
	g_cast_data.h_ray_data.horzhitdistance)
		set(1, i);
	else
		set(0, i);
	g_rays[i].ray_angle = ray_angle;
	g_rays[i].raydown = g_cast_data.raydown;
	g_rays[i].rayup = g_cast_data.rayup;
	g_rays[i].rayleft = g_cast_data.rayleft;
	g_rays[i].rayright = g_cast_data.rayright;
}
