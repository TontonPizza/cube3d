/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 04:50:15 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/19 04:50:15 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void			put_floor_to_img(t_game *g, t_tuple *img_xy, t_tuple *txy)
{
	int				index;
	int				gindex;
	char			shade[4];

	gindex = 4 * g->screen_x * img_xy->y + img_xy->x * 4;
	index = (txy->x % CELL) * 4 + (txy->y % CELL) * CELL * 4;
	if (index < 0 || gindex < 0)
		return ;
	if (index > CELL * 4 + CELL * 4 * 4 * CELL)
		return ;
	if (gindex > g->screen_x * 4 + g->screen_y * 4 * g->screen_x)
		return ;
	shadow(&(g->txt[4].data[index]), txy->range, shade);
	ft_memcpy(g->data + gindex,
			g->room == ROOM ? (void *)&(g->txt[11].data[index])
			: (void *)&(shade), 4);
}

void			put_skybox(t_game *g, float delta, t_tuple *img_xy)
{
	int		index;
	int		i;
	int		color;

	img_xy->y--;
	color = 0x000000;
	while (delta < 0)
		delta += M_PI * 2;
	while (delta > M_PI * 2)
		delta -= 2 * M_PI;
	index = floor(SKY_W * delta / (M_PI * 2));
	if (index >= 0 && index <= SKY_W)
	{
		i = SKY_H * 2 * img_xy->y / (g->screen_y / 2);
		ft_memcpy(g->data + 4 * g->screen_x * img_xy->y + img_xy->x * 4,
				g->room == ROOM ? (void*)&color :
				(void *)&(g->txt[6].data[4 * index + SKY_W * 4 * i]),
				sizeof(int));
	}
	img_xy->y++;
}

void			put_txt_to_img(t_game *g, t_tuple *img_xy, t_ray *ray)
{
	int				index;
	int				height;
	float			dist;
	char			shade[4];

	dist = abs(ray->dist * cos(ray->t - (float)g->p_t * RAD));
	height = ceil(WALL_COEFF * g->screen_y / dist);
	img_xy->y--;
	index = (img_xy->y - (g->screen_y - height) / 2) * CELL / height;
	if (!(img_xy->x < g->screen_x && img_xy->y < g->screen_y))
		return ;
	index = (img_xy->hit % CELL) * 4 + (index % CELL) * g->txt[0].size;
	index = ft_max(0, index);
	if (g->room == ROOM)
		shadow(&(g->txt[5].data[0]), ray->dist, shade);
	else
		shadow(&(g->txt[ray->txt].data[index]), ray->dist, shade);
	ft_memcpy(g->data + 4 * g->screen_x * img_xy->y + img_xy->x * 4,
			&(shade), sizeof(int));
	img_xy->y++;
}

void			draw_column_bonus(t_game *g, t_ray *r, int column, int hit)
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
		put_skybox(g, r->t, &(img[0]));
	while (img[0].y < (g->screen_y + height) / 2 && img[0].y++ < g->screen_y)
		put_txt_to_img(g, &(img[0]), r);
	while (img[0].y < (g->screen_y))
	{
		floor_cast(g, r, &(img[1]), img[0].y);
		put_floor_to_img(g, &(img[0]), &(img[1]));
		img[0].y++;
	}
}

int				render_scene_bonus(t_game *g)
{
	int		i;
	t_ray	rx;
	t_ray	ry;
	float	dists[g->screen_x];

	g->image = mlx_new_image(g->mlx, g->screen_x, g->screen_y);
	g->data = mlx_get_data_addr(g->image, &i, &i, &i);
	i = -1;
	while (++i < g->screen_x)
	{
		raycast_x(g, &rx, i, '1');
		raycast_y(g, &ry, i, '1');
		if (ry.valid != -1 && ry.dist < rx.dist && (dists[i] = ry.dist))
			draw_column_bonus(g, &ry, i, ry.hx);
		else
		{
			draw_column_bonus(g, &rx, i, rx.hy);
			dists[i] = rx.dist;
		}
	}
	set_time_variables(g);
	render_sprites(g, dists);
	return (0);
}
