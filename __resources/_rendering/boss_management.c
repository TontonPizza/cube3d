/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 03:09:47 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/24 03:09:47 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void		init_boss(t_game *g)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g->map_size_y)
	{
		j = 0;
		while (j < g->map_size_x)
		{
			if (g->map[i][j] == 'B')
			{
				g->boss_y = i * CELL + CELL / 2;
				g->boss_x = j * CELL + CELL / 2;
				return ;
			}
			j++;
		}
		i++;
	}
}

void		move_boss(t_game *g)
{
	int			dx;
	int			dy;
	int			newx;
	int			newy;

	if (g->room == ROOM)
		return ;
	if ((int)(floor)(g->fr) % 2 == 0)
		return ;
	dx = g->p_x - g->boss_x;
	dy = g->p_y - g->boss_y;
	newx = (int)(floor)(g->boss_x + BOSS_SPEED * sign(dx));
	newy = (int)(floor)(g->boss_y + BOSS_SPEED * sign(dy));
	if (ft_dist((float)(newx - g->p_x), (float)(newy - g->p_y)) < CELL)
	{
		return ;
	}
	g->boss_x = newx;
	g->boss_y = newy;
}

void		set_boss_prite_info(t_game *g, t_tuple *sxy)
{
	int		i;
	float	temp;

	i = 0;
	while (sxy[i].dist != -1)
		i++;
	sxy[i].x = g->boss_x;
	sxy[i].y = g->boss_y;
	sxy[i].dist = ft_dist((float)(g->p_y - sxy[i].y),
			(float)(g->p_x - sxy[i].x));
	if (sxy[i].dist == 0)
		sxy[i].teta = 0;
	else if (sxy[i].x >= g->p_x)
		sxy[i].teta = asin((g->p_y - sxy[i].y) / sxy[i].dist);
	else
		sxy[i].teta = -asin((g->p_y - sxy[i].y) / sxy[i].dist) + M_PI;
	temp = sxy[i].dist * (cos(sxy[i].teta - (float)g->p_t * RAD));
	sxy[i].dist = abs(temp);
	sxy[i].teta = g->p_t * RAD - sxy[i].teta;
	while (sxy[i].teta > M_PI)
		sxy[i].teta -= 2 * M_PI;
	while (sxy[i].teta < -M_PI)
		sxy[i].teta += 2 * M_PI;
	sxy[i].type = sxy[i].dist < 2 * CELL ? 'A' : 'B';
}
