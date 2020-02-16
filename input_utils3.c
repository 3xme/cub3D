/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:53:08 by abiari            #+#    #+#             */
/*   Updated: 2020/02/15 20:53:55 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_blanks(char *str)
{
	if (str)
	{
		while (*str == '\t' || *str == ' ')
			str++;
	}
	return (str);
}

int		store_no(char *line)
{
	int x;

	x = g_game_data.check;
	if ((x = (x & 0x00001000)) && (x == 0x00001000))
		return (-1);
	line = skip_blanks(line);
	if (!(g_game_data.paths.no = ft_strtrim(line, " \t")))
		return (-1);
	else
		g_game_data.check = g_game_data.check | 0x00001000;
	return (1);
}

int		store_so(char *line)
{
	int x;

	x = g_game_data.check;
	if ((x = (x & 0x00010000)) && (x == 0x00010000))
		return (-1);
	line = skip_blanks(line);
	if (!(g_game_data.paths.so = ft_strtrim(line, " \t")))
		return (-1);
	else
		g_game_data.check = g_game_data.check | 0x00010000;
	return (1);
}

int		store_we(char *line)
{
	int x;

	x = g_game_data.check;
	if ((x = (x & 0x00100000)) && (x == 0x00100000))
		return (-1);
	line = skip_blanks(line);
	if (!(g_game_data.paths.we = ft_strtrim(line, " \t")))
		return (-1);
	else
		g_game_data.check = g_game_data.check | 0x00100000;
	return (1);
}

int		store_ea(char *line)
{
	int x;

	x = g_game_data.check;
	if ((x = (x & 0x01000000)) && (x == 0x01000000))
		return (-1);
	line = skip_blanks(line);
	if (!(g_game_data.paths.ea = ft_strtrim(line, " \t")))
		return (-1);
	else
		g_game_data.check = g_game_data.check | 0x01000000;
	return (1);
}
