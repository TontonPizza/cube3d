/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 01:32:19 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/27 01:32:19 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void		render_intro(t_game *g, int scene)
{
	t_tuple	xy;
	int		rx;
	int		ry;

	if (g->image != NULL)
		mlx_destroy_image(g->mlx, g->image);
	g->image = mlx_new_image(g->mlx, g->screen_x, g->screen_y);
	g->data = mlx_get_data_addr(g->image, &rx, &rx, &rx);
	xy.x = (int)(g->screen_x * 0);
	while (xy.x < g->screen_x)
	{
		xy.y = (int)(g->screen_y * 0);
		while (xy.y < g->screen_y)
		{
			rx = floor((xy.x - (int)(g->screen_x * 0))
					* 650 / (g->screen_x * 1));
			ry = floor((xy.y - (int)(g->screen_y * 0))
					* 347 / (g->screen_y * 1));
			ft_memcpy(g->data + 4 * xy.x + g->screen_x * 4 * xy.y,
						g->txt[scene].data + rx * 4 + 650 * ry * 4, 4);
			xy.y++;
		}
		xy.x++;
	}
}

void		update_end_frame(t_game *g)
{
	clock_t now;
	int		delta;

	now = clock();
	delta = (now - g->ending_screen) / 70000;
	if (delta > 0)
		g->ending_screen = now;
	g->ef += delta;
	if (g->ef > 1500 - 400)
	{
		g->ef = 1500 - 400;
	}
}

void		render_outro(t_game *g, int scene)
{
	t_tuple xy;
	int		rx;
	int		ry;

	update_end_frame(g);
	if (g->image != NULL)
		mlx_destroy_image(g->mlx, g->image);
	g->image = mlx_new_image(g->mlx, g->screen_x, g->screen_y);
	g->data = mlx_get_data_addr(g->image, &rx, &rx, &rx);
	xy.x = (int)(g->screen_x * 0);
	while (xy.x < g->screen_x)
	{
		xy.y = (int)(g->screen_y * 0);
		while (xy.y < g->screen_y)
		{
			rx = floor((xy.x - (int)(g->screen_x * 0))
					* 650 / (g->screen_x * 1));
			ry = floor((xy.y - (int)(g->screen_y * 0))
					* 347 / (g->screen_y * 1));
			ft_memcpy(g->data + 4 * xy.x + g->screen_x * 4 * xy.y,
					g->txt[scene].data + rx * 4 + 650 * (ry + g->ef) * 4, 4);
			xy.y++;
		}
		xy.x++;
	}
}
