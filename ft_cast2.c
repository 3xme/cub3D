/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:40:09 by abiari            #+#    #+#             */
/*   Updated: 2020/02/15 20:18:41 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_h(void)
{
	g_cast_data.h_ray_data.horzwallhitx =
	g_cast_data.h_ray_data.nexthorztouchx;
	g_cast_data.h_ray_data.horzwallhity =
	g_cast_data.h_ray_data.nexthorztouchy;
	g_cast_data.h_ray_data.horzwallcontent =
	g_game_data.map.map[((int)(g_cast_data.h_ray_data.ytocheck /
	TILE_SIZE) * g_game_data.map.columns) +
	(int)(g_cast_data.h_ray_data.xtocheck / TILE_SIZE)];
	g_cast_data.h_ray_data.foundhorzwallhit = 1;
}

void	init_h_data(float ray_angle)
{
	g_cast_data.h_ray_data.horzwallcontent = 0;
	g_cast_data.h_ray_data.horzwallhitx = 0;
	g_cast_data.h_ray_data.horzwallhity = 0;
	g_cast_data.h_ray_data.foundhorzwallhit = 0;
	g_cast_data.yhintercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	g_cast_data.yhintercept += g_cast_data.raydown ? TILE_SIZE : 0;
	g_cast_data.xhintercept = g_player.x - ((g_player.y -
	g_cast_data.yhintercept) / tan(ray_angle * RAD));
	g_cast_data.ystep = TILE_SIZE;
	g_cast_data.ystep *= g_cast_data.rayup ? -1 : 1;
	g_cast_data.xstep = g_cast_data.ystep / tan(ray_angle * RAD);
	g_cast_data.h_ray_data.nexthorztouchx = g_cast_data.xhintercept;
	g_cast_data.h_ray_data.nexthorztouchy = g_cast_data.yhintercept;
}

void	h_ray_inter(float ray_angle)
{
	int check;

	init_h_data(ray_angle);
	check = g_cast_data.raydown ? 0 : -1;
	while (g_cast_data.h_ray_data.nexthorztouchx >= 0 &&
	g_cast_data.h_ray_data.nexthorztouchx <= g_game_data.map.columns *
	TILE_SIZE && g_cast_data.h_ray_data.nexthorztouchy >= 0 &&
	g_cast_data.h_ray_data.nexthorztouchy <= g_game_data.map.rows * TILE_SIZE)
	{
		g_cast_data.h_ray_data.xtocheck = g_cast_data.h_ray_data.nexthorztouchx;
		g_cast_data.h_ray_data.ytocheck = g_cast_data.h_ray_data.nexthorztouchy;
		if (has_wall(g_cast_data.h_ray_data.xtocheck,
		g_cast_data.h_ray_data.ytocheck + check))
		{
			set_h();
			break ;
		}
		else
		{
			g_cast_data.h_ray_data.nexthorztouchx += g_cast_data.xstep;
			g_cast_data.h_ray_data.nexthorztouchy += g_cast_data.ystep;
		}
	}
}

void	affect_distance(void)
{
	g_cast_data.h_ray_data.horzhitdistance =
	g_cast_data.h_ray_data.foundhorzwallhit
	? hypot(g_cast_data.h_ray_data.horzwallhitx -
	g_player.x, g_cast_data.h_ray_data.horzwallhity - g_player.y)
	: INT_MAX;
	g_cast_data.v_ray_data.verthitdistance =
	g_cast_data.v_ray_data.foundvertwallhit
	? hypot(g_cast_data.v_ray_data.vertwallhitx -
	g_player.x, g_cast_data.v_ray_data.vertwallhity - g_player.y)
	: INT_MAX;
}

void	set(int flag, int i)
{
	if (flag == 1)
	{
		g_rays[i].distance = g_cast_data.v_ray_data.verthitdistance;
		g_rays[i].wallhitx = g_cast_data.v_ray_data.vertwallhitx;
		g_rays[i].wallhity = g_cast_data.v_ray_data.vertwallhity;
		g_rays[i].wallhitcontent = g_cast_data.v_ray_data.vertwallcontent;
		g_rays[i].washitvertical = 1;
	}
	else
	{
		g_rays[i].distance = g_cast_data.h_ray_data.horzhitdistance;
		g_rays[i].wallhitx = g_cast_data.h_ray_data.horzwallhitx;
		g_rays[i].wallhity = g_cast_data.h_ray_data.horzwallhity;
		g_rays[i].wallhitcontent = g_cast_data.h_ray_data.horzwallcontent;
		g_rays[i].washitvertical = 0;
	}
}
