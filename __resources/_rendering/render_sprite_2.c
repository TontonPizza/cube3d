/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 03:25:17 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/16 03:25:17 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void		draw_bonus(t_game *g, int index, int n, int height)
{
	int		i;
	int		ri;
	int		y;
	int		f;

	f = (int)floor(g->fr) % g->frc[(int)g->cs];
	i = 0;
	while (i < height)
	{
		ri = i * CELL / height;
		y = g->screen_x * 4 * (i + g->screen_y / 2 - (height / 2));
		if (!(y > g->screen_x * g->screen_y * 4 || y < -index * 4))
		{
			if (ft_strncmp(g->spr[(int)g->cs][f].data,
					g->spr[(int)g->cs][f].data + n * 4 + ri * CELL * 4, 4))
			{
				ft_memcpy(g->data + index * 4 + y, &(g->spr[(int)g->cs]
				[f].data[n * 4 + ri * CELL * 4]), 4);
			}
		}
		i++;
	}
}

void		draw_sprite(t_game *g, int index, int n, int height)
{
	int		i;
	int		ri;
	int		y;

	i = 0;
	while (i < height)
	{
		ri = i * CELL / height;
		y = g->screen_x * 4 * (i + g->screen_y / 2 - (height / 2));
		if (!(y > g->screen_x * g->screen_y * 4 || y < -index * 4))
		{
			if (ft_strncmp(g->txt[5].data,
					g->txt[5].data + n * 4 + ri * CELL * 4, 4) != 0)
			{
				ft_memcpy(g->data + index * 4 + y,
						&(g->txt[5].data[n * 4 + ri * CELL * 4]), 4);
			}
		}
		i++;
	}
}

void		render_sprites_2(t_game *g, float *dists, t_tuple *sxy, int item)
{
	int		width;
	int		i;
	float	rt;
	float	index;

	width = ceil(WALL_COEFF * g->screen_y / sxy[item].dist);
	i = 0;
	g->cs = sxy[item].type;
	while (i < width && width < g->screen_x * 3 && (index = -1) + 2)
	{
		rt = sxy[item].teta + atan(CELL / (2 * sxy[item].dist)) -
			i * 2 * atan(CELL / (2 * sxy[item].dist)) / (float)width;
		if (rt < TETA * RAD / 2 && rt > -TETA * RAD / 2)
			index = (g->screen_x / 2) + (rt / (TETA * RAD)) * g->screen_x;
		if (dists[(int)index] > sxy[item].dist && !g->bonus && i++)
		{
			draw_sprite(g, (int)index, i * CELL / width, width);
			draw_sprite(g, (int)index + 1, i * CELL / width, width);
		}
		else if (i++ && dists[(int)index] > sxy[item].dist && g->bonus)
		{
			draw_bonus(g, (int)index, (i - 1) * CELL / width, width);
			draw_bonus(g, (int)index + 1, (i - 1) * CELL / width, width);
		}
	}
}
