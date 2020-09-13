/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 03:14:22 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/27 03:14:22 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

int			put_image_and_destroy(t_game *g)
{
	if (g->image == NULL)
		g->image = mlx_new_image(g->mlx, g->screen_x, g->screen_y);
	mlx_put_image_to_window(g->mlx, g->window, g->image, 0, 0);
	mlx_destroy_image(g->mlx, g->image);
	g->image = NULL;
	return (0);
}

void		grab_bonus(t_game *g)
{
	int		x;
	int		y;

	x = g->p_x / 64;
	y = g->p_y / 64;
	if (x >= 0 && x < g->map_size_x && y >= 0 && y < g->map_size_y)
	{
		if (g->map[y][x] == CRYSTAL_SPRITE)
		{
			g->player_hp = HP_MAX;
			g->map[y][x] = FLOOR_SPRITE;
			play_sound_1(g, "sounds/life.wav");
		}
	}
}
