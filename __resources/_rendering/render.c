/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:57:41 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/12 20:57:41 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void		put_pxl_to_img(t_game *g, t_tuple *img_xy, unsigned char color[4])
{
	img_xy->y--;
	if (img_xy->x < g->screen_x && img_xy->y < g->screen_y)
	{
		ft_memcpy(g->data + 4 * g->screen_x * img_xy->y + img_xy->x * 4,
				color, sizeof(int));
	}
	img_xy->y++;
}

void		draw_column(t_game *g, t_ray *r, int column, int hit)
{
	float		dist;
	int			height;
	t_tuple		img[2];

	dist = abs(r->dist * cos((r->t - (float)g->p_t * RAD)));
	height = ceil(WALL_COEFF * g->screen_y / dist);
	img[0].x = column;
	img[0].hit = hit;
	img[0].y = 0;
	while (img[0].y++ < (g->screen_y - height) / 2)
		put_pxl_to_img(g, &(img[0]), g->floor);
	while (img[0].y < (g->screen_y + height) / 2 && img[0].y++ < g->screen_y)
		put_txt_to_img(g, &(img[0]), r);
	while (img[0].y++ < (g->screen_y))
		put_pxl_to_img(g, &(img[0]), g->ceiling);
}

int			render_scene(t_game *g)
{
	int		i;
	t_ray	rx;
	t_ray	ry;
	float	dists[g->screen_x];

	g->image = mlx_new_image(g->mlx, g->screen_x, g->screen_y);
	g->data = mlx_get_data_addr(g->image, &i, &i, &i);
	i = 0;
	while (i < g->screen_x)
	{
		raycast_x(g, &rx, i, '1');
		raycast_y(g, &ry, i, '1');
		if (ry.valid != -1 && ry.dist < rx.dist && (dists[i] = ry.dist))
			draw_column(g, &ry, i, ry.hx);
		else
		{
			draw_column(g, &rx, i, rx.hy);
			dists[i] = rx.dist;
		}
		i++;
	}
	render_sprites(g, dists);
	mlx_put_image_to_window(g->mlx, g->window, g->image, 0, 0);
	return (mlx_destroy_image(g->mlx, g->image));
}

void		render_bitmap(t_game *g)
{
	int		i;
	t_ray	rx;
	t_ray	ry;
	float	dists[g->screen_x];

	g->image = mlx_new_image(g->mlx, g->screen_x, g->screen_y);
	g->data = mlx_get_data_addr(g->image, &i, &i, &i);
	i = 0;
	while (i < g->screen_x)
	{
		raycast_x(g, &rx, i, '1');
		raycast_y(g, &ry, i, '1');
		if (ry.valid != -1 && ry.dist < rx.dist && (dists[i] = ry.dist))
			draw_column(g, &ry, i, ry.hx);
		else
		{
			draw_column(g, &rx, i, rx.hy);
			dists[i] = rx.dist;
		}
		i++;
	}
	render_sprites(g, dists);
	write_bmp("full.bmp", g);
	g->window = NULL;
	destroy_game_data_full(g, 1);
}
