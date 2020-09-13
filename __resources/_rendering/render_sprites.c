/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 01:06:55 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/14 01:06:55 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void			set_sprite_struct(t_game *g, t_tuple *sxy, int i, int j)
{
	float	temp;

	sxy->x = j * CELL + CELL / 2;
	sxy->y = i * CELL + CELL / 2;
	sxy->dist = ft_dist((float)(g->p_y - sxy->y), (float)(g->p_x - sxy->x));
	if (sxy->dist == 0)
		sxy->teta = 0;
	else if (sxy->x >= g->p_x)
		sxy->teta = asin((g->p_y - sxy->y) / sxy->dist);
	else
		sxy->teta = -asin((g->p_y - sxy->y) / sxy->dist) + M_PI;
	temp = sxy->dist * (cos(sxy->teta - (float)g->p_t * RAD));
	sxy->dist = abs(temp);
	sxy->teta = g->p_t * RAD - sxy->teta;
	while (sxy->teta > M_PI)
		sxy->teta -= 2 * M_PI;
	while (sxy->teta < -M_PI)
		sxy->teta += 2 * M_PI;
}

void			swap_data(t_tuple *s1, t_tuple *s2)
{
	t_tuple temp;

	temp.x = s1->x;
	temp.y = s1->y;
	temp.teta = s1->teta;
	temp.dist = s1->dist;
	temp.type = s1->type;
	s1->y = s2->y;
	s1->x = s2->x;
	s1->dist = s2->dist;
	s1->teta = s2->teta;
	s1->type = s2->type;
	s2->dist = temp.dist;
	s2->x = temp.x;
	s2->y = temp.y;
	s2->teta = temp.teta;
	s2->type = temp.type;
}

void			order_sxy_by_dist(t_game *g, t_tuple *sxy)
{
	int			i;
	int			has_changed;

	if (g->bonus)
		set_boss_prite_info(g, sxy);
	has_changed = 1;
	i = 0;
	while (has_changed)
	{
		has_changed = 0;
		i = 0;
		while (sxy[i + 1].dist != -1)
		{
			if (sxy[i + 1].dist > sxy[i].dist)
			{
				swap_data((sxy + i + 1), (sxy + i));
				has_changed = 1;
				i = 0;
			}
			i++;
		}
	}
}

void			fill_sprite_location(t_game *g, t_tuple *sxy)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (j < g->map_size_x * g->map_size_y)
		sxy[j++].dist = -1;
	while (i < g->map_size_y)
	{
		j = 0;
		while (j < g->map_size_x)
		{
			if (g->map[i][j] >= '2' && g->map[i][j] <= '6')
			{
				set_sprite_struct(g, sxy + k, i, j);
				sxy[k].type = g->map[i][j];
				k++;
			}
			j++;
		}
		i++;
	}
	order_sxy_by_dist(g, sxy);
}

void			render_sprites(t_game *g, float *dists)
{
	int			i;
	t_tuple		sxy[g->map_size_y * g->map_size_x];

	i = 0;
	fill_sprite_location(g, sxy);
	move_boss(g);
	while (sxy[i].dist != -1)
	{
		render_sprites_2(g, dists, sxy, i);
		i++;
	}
}
