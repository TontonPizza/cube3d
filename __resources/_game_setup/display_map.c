/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 23:29:46 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/29 23:29:46 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void		display_map(t_game *map)
{
	int i;

	i = 0;
	ft_printf("Resolution = %d * %d\n", map->screen_x, map->screen_y);
	ft_printf("NO = %30s\n", map->t_north);
	ft_printf("SO = %30s\n", map->t_south);
	ft_printf("WE = %30s\n", map->t_west);
	ft_printf("EA = %30s\n", map->t_east);
	ft_printf("S = %30s\n", map->t_sprite);
	ft_printf("F = 0x%u\n", (map->floor[3]));
	ft_printf("c = 0x%u\n", (map->ceiling[3]));
	while (map->map[i] != NULL && map->map[i][0] != '\n')
	{
		ft_printf("%s - %d\n", map->map[i], i);
		i++;
	}
	ft_printf("map size = %d * %d\n", map->map_size_x, map->map_size_y);
	ft_printf("map 2 1 = %c\n", map->map[2][1]);
}
