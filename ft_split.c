/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiari <abiari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:40:42 by abiari            #+#    #+#             */
/*   Updated: 2020/02/14 16:18:18 by abiari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int		ft_wlen(char const *str, int i, int *nbword, int c)
{
	*nbword += 1;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

static	int		ft_fill(char **tab, char const *str, int *nbword, int c)
{
	int		wlen;
	int		j;
	char	*tmp;
	int		sv;

	wlen = 0;
	sv = 0;
	while (str[wlen] != c && str[wlen] != '\0')
		wlen++;
	if (!(tmp = (char *)MALLOC((wlen + 1) * sizeof(char))))
	{
		*nbword = 0;
		return (ft_strlen(str));
	}
	tmp[wlen] = '\0';
	j = 0;
	while (sv < wlen)
	{
		tmp[j] = str[sv++];
		j++;
	}
	tab[*nbword] = tmp;
	*nbword += 1;
	return (wlen);
}

static	void	reset(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char			**ft_split(char const *str, char c)
{
	int		i;
	char	**tab;
	int		number_words;

	reset(&i, &number_words);
	if (!str)
		return (NULL);
	while (str[i] != '\0')
		if (str[i] != c)
			i = ft_wlen(str, i, &number_words, c);
		else
			i++;
	if (!(tab = (char **)MALLOC((number_words + 1) * sizeof(char *))))
		return (NULL);
	tab[number_words] = 0;
	reset(&i, &number_words);
	while (str[i] != '\0')
		if (str[i] != c)
			i += ft_fill(tab, str + i, &number_words, c);
		else
			i++;
	if (!number_words && !tab)
		return (NULL);
	return (tab);
}
