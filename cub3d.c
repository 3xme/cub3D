/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:36:05 by abiari            #+#    #+#             */
/*   Updated: 2020/02/16 00:05:59 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render3d(void)
{
	float	ray_angle;
	int		x;
	int		i;

	x = 0;
	i = 0;
	ray_angle = g_player.rotation_angle - (FOV_ANGLE / 2);
	while (ray_angle < g_player.rotation_angle + (FOV_ANGLE / 2))
	{
		cast_ray(ray_angle, i);
		putstripes(ray_angle, x, i);
		ray_angle += (float)FOV_ANGLE / g_num_rays;
		x++;
		i++;
	}
}

int		render_frames(void)
{
	float new_x;
	float new_y;

	new_x = cos(g_player.rotation_angle * RAD) * 10;
	new_y = sin(g_player.rotation_angle * RAD) * 10;
	if (g_player.turn_direction == 1)
		g_player.rotation_angle += 3;
	else if (g_player.turn_direction == -1)
		g_player.rotation_angle -= 3;
	move_y(new_x, new_y);
	move_x(new_x, new_y);
	black_img();
	render3d();
	update_sp_d();
	sprites();
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_img.img_ptr, 0, 0);
	return (0);
}

int		treat_texture(void)
{
	int i;

	i = -1;
	g_textures[0].ptr = mlx_xpm_file_to_image(g_mlx_ptr, g_game_data.paths.no,
	&g_textures[0].width, &g_textures[0].height);
	g_textures[1].ptr = mlx_xpm_file_to_image(g_mlx_ptr, g_game_data.paths.so,
	&g_textures[1].width, &g_textures[1].height);
	g_textures[2].ptr = mlx_xpm_file_to_image(g_mlx_ptr, g_game_data.paths.ea,
	&g_textures[2].width, &g_textures[2].height);
	g_textures[3].ptr = mlx_xpm_file_to_image(g_mlx_ptr, g_game_data.paths.we,
	&g_textures[3].width, &g_textures[3].height);
	while (++i < 4)
		if (g_textures[i].ptr == NULL)
			return (0);
	i = -1;
	while (++i < 4)
		g_textures[i].addr = (int *)mlx_get_data_addr(g_textures[i].ptr,
		&g_textures[i].bpp, &g_textures[i].line_length, &g_textures[i].endian);
	return (1);
}

void	init(void)
{
	g_mlx_ptr = mlx_init();
	g_win_ptr = mlx_new_window(g_mlx_ptr,
	g_game_data.res.width, g_game_data.res.height, "cub3d");
	g_img.img_ptr = mlx_new_image(g_mlx_ptr,
	g_game_data.res.width, g_game_data.res.height);
	g_img.addr = mlx_get_data_addr(g_img.img_ptr,
	&g_img.bpp, &g_img.line_length, &g_img.endian);
	g_num_rays = g_game_data.res.width;
}

int		main(int argc, char **argv)
{
	if (argc < 2 && write(2, ".cub file input missing!", 24))
		exit(0);
	if (argc > 3 && write(2, "too many arguments!", 19))
		exit(0);
	check_cub(argc, argv);
	if (set_route(read_input(argv[1])) == -1)
	{
		write(2, "error", 5);
		exit(0);
	}
	init();
	if (!treat_texture())
	{
		write(2, "error", 5);
		exit(0);
	}
	sp_pos();
	player_pos();
	save(argc, argv);
	mlx_hook(g_win_ptr, 2, 1L << 0, key_pressed, (void *)0);
	mlx_hook(g_win_ptr, 3, 1L << 1, key_released, (void *)0);
	mlx_hook(g_win_ptr, 17, 0L, destroy_window, (void *)0);
	mlx_loop_hook(g_mlx_ptr, render_frames, (void *)0);
	mlx_loop(g_mlx_ptr);
	return (0);
}
