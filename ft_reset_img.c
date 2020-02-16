/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:14:36 by abiari            #+#    #+#             */
/*   Updated: 2020/02/15 18:15:12 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	black_img(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_game_data.res.width)
	{
		j = 0;
		while (j < g_game_data.res.height)
		{
			if ((i >= 0 && i < g_game_data.res.width) &&
				(j >= 0 && j < g_game_data.res.height))
				mlx_img_mod(i, j, 0x000000);
			j++;
		}
		i++;
	}
}
