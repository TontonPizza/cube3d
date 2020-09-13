/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 03:00:40 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/12 03:00:40 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

int		cmp(char *s1, int len)
{
	int strlens1;

	strlens1 = ft_strlen(s1);
	if (strlens1 > MAP_SIZE || strlens1 != len)
	{
		return (1);
	}
	return (0);
}

int		map_val_return(t_game *g, int len, int i)
{
	g->map_size_x = len;
	g->map_size_y = i;
	return (1);
}

int		map_validator(t_game *g)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	j;

	i = 0;
	j = 0;
	len = ft_strlen(g->map[0]);
	while (g->map[i] != NULL)
	{
		if (g->map[i][0] != '1' || g->map[i][len - 1] != '1'
				|| cmp(g->map[i], len) || (i++) + 1 < 1)
			return (error_message("invalid map : size", g, 1));
	}
	while (j < len)
	{
		if (g->map[0][j] != '1' || g->map[i - 1][j] != '1' || (j++) + 1 < 1)
			return (error_message("invalid map : boder error", g, 1));
	}
	j = 0;
	while (j < i)
	{
		if (ft_inset_s(g->map[j++], g->bonus ? VALID_B : VALID_CHAR) == 0)
			return (error_message("invalid map : invalid char", g, 1));
	}
	return (map_val_return(g, len, i));
}

int		map_validator_2(t_game *game, int mapsize)
{
	int		p;
	int		i;
	int		j;
	int		len;

	p = 0;
	i = 0;
	j = 0;
	len = MAP_SIZE;
	if (mapsize >= MAP_SIZE)
		return (error_message("map is too big", game, 1));
	while (game->map[i] != NULL)
	{
		j = 0;
		while (j < len)
		{
			if (ft_inset_c(game->map[i][j], "NSEW"))
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		return (error_message("invalid map : too many players", game, 1));
	return (1);
}
