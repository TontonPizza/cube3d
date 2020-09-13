/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 20:14:19 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/24 20:14:19 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void		render_gun(t_game *g)
{
	t_tuple xy;
	int		rx;
	int		ry;
	int		f;

	f = g->is_shooting ? (int)(floor(g->frgun)) % 4 + 1 : 0;
	xy.x = (int)(g->screen_x * 0);
	while (xy.x < g->screen_x && g->player_gun != 0)
	{
		xy.y = (int)(g->screen_y * 0);
		while (xy.y < g->screen_y)
		{
			rx = floor((xy.x - (int)(g->screen_x * 0))
					* 286 / (g->screen_x * 1));
			ry = floor((xy.y - (int)(g->screen_y * 0))
					* 139 / (g->screen_y * 1));
			if (ft_strncmp(g->spr['G'][f].data,
					g->spr['G'][f].data + rx * 4 + 286 * ry * 4, 4))
				ft_memcpy(g->data + 4 * xy.x + g->screen_x * 4 * xy.y,
					g->spr['G'][f].data + rx * 4 + 286 * ry * 4, 4);
			xy.y++;
		}
		xy.x++;
	}
}

void		render_hp(t_game *g)
{
	t_tuple xy;

	xy.hit = g->player_hp <= HP_MAX / 2 ? 0x8b0000 : 0x008000;
	xy.y = (int)(floor(g->screen_y * 0.94f));
	while (xy.y < (int)(floor(g->screen_y * 0.96f)))
	{
		xy.x = (int)(floor(g->screen_x * 0.03f));
		while (xy.x < g->screen_x * 0.25f * (g->player_hp) / (float)(HP_MAX))
		{
			ft_memcpy(g->data + 4 * xy.x + g->screen_x * 4 * xy.y,
					&(xy.hit), 4);
			xy.x++;
		}
		xy.y++;
	}
}

void		render_boss_hp(t_game *g)
{
	t_tuple xy;

	xy.hit = g->boss_hp <= HP_BOSS_MAX / 2 ? 0x8b0000 : 0x008000;
	xy.y = (int)(floor(g->screen_y * 0.04f));
	while (xy.y < (int)(floor(g->screen_y * 0.06f)))
	{
		xy.x = (int)(floor(g->screen_x * 0.15f));
		while (xy.x < g->screen_x * 0.85f * (g->boss_hp) / (float)(HP_BOSS_MAX))
		{
			ft_memcpy(g->data + 4 * xy.x + g->screen_x * 4 * xy.y,
					&(xy.hit), 4);
			xy.x++;
		}
		xy.y++;
	}
}

void		render_gui(t_game *g)
{
	if (g->room == 1)
		return ;
	render_gun(g);
	render_hp(g);
	if (ft_dist(g->p_y - g->boss_y, g->p_x - g->boss_x) < 8 * CELL)
		render_boss_hp(g);
}
