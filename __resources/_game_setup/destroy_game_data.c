/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 03:02:43 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/12 03:02:43 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void		destroy_game_data(t_game *gd)
{
	int i;

	i = 0;
	free(gd->t_sprite);
	free(gd->t_east);
	free(gd->t_west);
	free(gd->t_north);
	free(gd->t_south);
	while (gd->map[i] != NULL)
	{
		free(gd->map[i]);
		i++;
	}
	free(gd->map);
	exit(0);
}

void		destroy_animation(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 256)
	{
		j = 0;
		while (j < g->frc[i])
		{
			mlx_destroy_image(g->mlx, g->spr[i][j].img);
			j++;
		}
		i++;
	}
}

void		destroy_game_data_full(t_game *g, int mode)
{
	int		i;

	destroy_game_data(g);
	i = 0;
	while (i < 5)
		mlx_destroy_image(g->mlx, g->txt[i++].img);
	if (g->bonus == 1)
	{
		mlx_destroy_image(g->mlx, g->txt[5].img);
		mlx_destroy_image(g->mlx, g->txt[6].img);
		mlx_destroy_image(g->mlx, g->txt[7].img);
		mlx_destroy_image(g->mlx, g->txt[8].img);
		mlx_destroy_image(g->mlx, g->txt[9].img);
		mlx_destroy_image(g->mlx, g->txt[10].img);
		mlx_destroy_image(g->mlx, g->txt[11].img);
		mlx_destroy_image(g->mlx, g->txt[12].img);
		mlx_destroy_image(g->mlx, g->txt[13].img);
		destroy_animation(g);
	}
	if (g->window != NULL && mode == 1)
	{
		mlx_destroy_window(g->mlx, g->window);
		exit(0);
	}
}
