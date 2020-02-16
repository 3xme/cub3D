/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:47:04 by abiari            #+#    #+#             */
/*   Updated: 2020/02/15 23:09:13 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_cub(int argc, char **argv)
{
	int	i;

	if (argc == 2 || argc == 3)
	{
		i = 0;
		while (argv[1][i] != '.')
			i++;
		i++;
		if (ft_strlen(&argv[1][i]) != 3)
		{
			write(2, "not a .cub file!", 16);
			exit(0);
		}
		else if (ft_strcmp(&argv[1][i], "cub"))
		{
			write(2, "not a .cub file!", 16);
			exit(0);
		}
	}
}
