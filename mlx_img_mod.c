/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:47:54 by abiari            #+#    #+#             */
/*   Updated: 2020/02/14 16:07:54 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_img_mod(int x, int y, int color)
{
	char	*dst;

	dst = g_img.addr + ((x * 4) + (g_img.line_length * y));
	*(unsigned int*)dst = (unsigned int)color;
}
