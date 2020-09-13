/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 02:52:50 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/26 02:52:50 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void	destroy_triangle(t_game *g)
{
	int x;
	int y;
	int i;
	int j;

	x = g->p_x / 64;
	y = g->p_y / 64;
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			if (g->map[y + i][x + j] == TRIANGLE_SPRITE)
			{
				g->map[y + i][x + j] = '0';
				play_sound_1(g, "sounds/glass.wav");
			}
			j++;
		}
		i++;
	}
}

void	knockback(t_game *g)
{
	int			newx;
	int			newy;
	int			dx;
	int			dy;

	if (ft_dist(g->p_x - g->boss_x, g->p_y - g->boss_y) < 2.1f * CELL)
	{
		dx = g->p_x - g->boss_x;
		dy = g->p_y - g->boss_y;
		newx = (int)(floor)(g->boss_x - 30 * sign(dx));
		newy = (int)(floor)(g->boss_y - 30 * sign(dy));
		g->boss_x = newx;
		g->boss_y = newy;
		g->boss_hp = g->boss_hp - 1;
		play_sound_1(g, "sounds/hit2.wav");
	}
}

int		attack(t_game *g)
{
	clock_t		now;

	now = clock();
	if (g->player_gun == 0)
		return (0);
	if (now - g->last_attack > COOL_DOWN / 2)
	{
		g->is_shooting = 1;
		g->last_attack = now;
		knockback(g);
		destroy_triangle(g);
	}
	return (0);
}
