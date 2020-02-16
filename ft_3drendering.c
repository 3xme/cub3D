/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3drendering.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:07:06 by abiari            #+#    #+#             */
/*   Updated: 2020/02/14 20:07:14 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_stripe(float ray_angle, int k)
{
	g_wall.perpdistance = g_rays[k].distance *
	cos((ray_angle - g_player.rotation_angle) * RAD);
	g_wall.distanceprojplane = (g_game_data.res.width / 2) /
	tan((FOV_ANGLE / 2) * RAD);
	g_wall.projectedwallheight = (TILE_SIZE / g_wall.perpdistance) *
	g_wall.distanceprojplane;
	g_wall.wallstripeheight = (int)g_wall.projectedwallheight;
	g_wall.walltoppixel = (g_game_data.res.height / 2) -
	(g_wall.wallstripeheight / 2);
	g_wall.walltoppixel = g_wall.walltoppixel < 0 ? 0 : g_wall.walltoppixel;
	g_wall.wallbottompixel = (g_game_data.res.height / 2) +
	(g_wall.wallstripeheight / 2);
	g_wall.wallbottompixel = g_wall.wallbottompixel > g_game_data.res.height ?
	g_game_data.res.height : g_wall.wallbottompixel;
}

void	ceiling(int x)
{
	while (g_wall.i < g_wall.walltoppixel)
	{
		if ((x >= 0 && x < g_game_data.res.width) &&
		(g_wall.i >= 0 && g_wall.i < g_game_data.res.height))
			mlx_img_mod(x, g_wall.i, rgbtoint(g_game_data.c.r,
			g_game_data.c.g, g_game_data.c.b));
		g_wall.i++;
	}
}

void	wall(int x)
{
	while (g_wall.i < g_wall.wallbottompixel)
	{
		g_wall.distancefromtop = g_wall.i + ((g_wall.wallstripeheight / 2) -
		(g_game_data.res.height / 2));
		g_wall.textureoffsety = g_wall.distancefromtop *
		((float)g_textures[g_wall.j].height / g_wall.wallstripeheight);
		g_wall.color = g_textures[g_wall.j].addr[(g_textures[g_wall.j].width *
		g_wall.textureoffsety) + g_wall.textureoffsetx];
		if ((x >= 0 && x < g_game_data.res.width) && (g_wall.i >= 0 &&
		g_wall.i < g_game_data.res.height))
			mlx_img_mod(x, g_wall.i, g_wall.color);
		g_wall.i++;
	}
}

void	grownd(int x)
{
	while (g_wall.i < g_game_data.res.height)
	{
		if ((x >= 0 && x < g_game_data.res.width) &&
			(g_wall.i >= 0 && g_wall.i < g_game_data.res.height))
			mlx_img_mod(x, g_wall.i, rgbtoint(g_game_data.f.r,
						g_game_data.f.g, g_game_data.f.b));
		g_wall.i++;
	}
}

void	putstripes(float ray_angle, int x, int k)
{
	init_stripe(ray_angle, k);
	if (!g_rays[k].washitvertical)
		g_wall.j = g_rays[k].raydown ? 0 : 1;
	else
		g_wall.j = g_rays[k].rayleft ? 3 : 2;
	if (g_rays[k].washitvertical)
		g_wall.textureoffsetx = (int)g_rays[k].wallhity % TILE_SIZE;
	else
		g_wall.textureoffsetx = (int)g_rays[k].wallhitx % TILE_SIZE;
	g_wall.i = 0;
	ceiling(x);
	g_wall.i = g_wall.walltoppixel;
	wall(x);
	g_wall.i = g_wall.wallbottompixel;
	grownd(x);
}
