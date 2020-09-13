/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 02:22:53 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/04 02:22:53 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

int			raycast_y(t_game *gd, t_ray *r, int c, char object)
{
	int			i;
	char		cell;

	i = 0;
	cell = 'X';
	r->t = (gd->p_t + TETA / 2.0f - c * ((float)TETA / gd->screen_x)) * RAD;
	if (sin(r->t) == 0)
		return (-1);
	r->hy = sin(r->t) > 0 ? floor((float)(gd->p_y) / CELL) * CELL :
			ceil((float)(gd->p_y) / CELL) * CELL;
	while (cell != object && i < gd->map_size_y)
	{
		r->hy = r->hy - (i != 0 ? sign(sin(r->t)) * CELL : 0);
		r->hx = abs((gd->p_y - r->hy) / sin(r->t)) * (cos(r->t)) + gd->p_x;
		r->dist = ft_dist(gd->p_y - r->hy, gd->p_x - r->hx);
		if ((r->hy + sign(r->hy - gd->p_y)) / CELL < gd->map_size_y
			&& (r->hx + sign(r->hx - gd->p_x)) / CELL < gd->map_size_x)
		{
			cell = gd->map[ft_max(0, (r->hy + sign(r->hy - gd->p_y)) / CELL)]
				[ft_max(0, (r->hx + sign(r->hx - gd->p_x)) / CELL)];
		}
		i++;
	}
	r->txt = r->hy > gd->p_y ? 1 : 0;
	return (r->valid = (cell == object));
}

int			raycast_x(t_game *gd, t_ray *r, int c, char object)
{
	int			i;
	char		cell;

	cell = 'X';
	i = 0;
	r->t = (gd->p_t + TETA / 2.0f - c * ((float)TETA / gd->screen_x)) * RAD;
	if (cos(r->t) == 0)
		return (-1);
	r->hx = cos(r->t) > 0 ? ceil((float)(gd->p_x) / CELL) * CELL :
			floor((float)(gd->p_x) / CELL) * CELL;
	while (cell != object && i < gd->map_size_x)
	{
		r->hx = r->hx + (i != 0 ? sign(cos(r->t)) * CELL : 0);
		r->hy = abs((gd->p_x - r->hx) / cos(r->t)) * (-sin(r->t)) + gd->p_y;
		r->dist = ft_dist(gd->p_y - r->hy, gd->p_x - r->hx);
		if ((r->hy + sign(r->hy - gd->p_y)) / CELL < gd->map_size_y
			&& (r->hx + sign(r->hx - gd->p_x)) / CELL < gd->map_size_x)
		{
			cell = gd->map[ft_max(0, (r->hy + sign(r->hy - gd->p_y)) / CELL)]
					[ft_max(0, (r->hx + sign(r->hx - gd->p_x)) / CELL)];
		}
		i++;
	}
	r->txt = r->hx > gd->p_x ? 2 : 3;
	return (r->valid = (cell == object));
}

void		floor_cast(t_game *g, t_ray *r, t_tuple *t, int delta)
{
	float	dist;
	float	omega;

	omega = (OMEGA * RAD / 2) * (delta - g->screen_y / 2) /
			(float)g->screen_y;
	if (omega <= 0.02f && omega >= -0.02f)
		omega = 0.02f;
	dist = g->p_h * sin(M_PI / 2 - omega) / cos(M_PI / 2 - omega);
	t->x = (int)floor((g->p_x + dist * cos(r->t)));
	t->y = ((int)floor((g->p_y + dist * -sin(r->t))));
	t->range = dist;
}
