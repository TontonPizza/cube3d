/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 03:07:16 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/12 03:07:16 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

int		check_files(t_game *g)
{
	int		fd[7];

	fd[0] = open(g->t_north, O_RDONLY);
	fd[1] = open(g->t_south, O_RDONLY);
	fd[2] = open(g->t_east, O_RDONLY);
	fd[3] = open(g->t_west, O_RDONLY);
	fd[4] = open(g->t_sprite, O_RDONLY);
	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0 || fd[3] < 0 || fd[4] < 0)
	{
		error_message("Can't load textures 0 1 2 3 4\n", g, 1);
		destroy_game_data(g);
	}
	if (g->bonus == 1)
	{
		fd[5] = open(g->t_floor, O_RDONLY);
		fd[6] = open(g->t_sky, O_RDONLY);
		if (fd[5] < 0 || fd[6] < 0)
		{
			printf("%d %d\n", fd[5], fd[6]);
			error_message("Can't load textures\n", g, 1);
			destroy_game_data(g);
		}
	}
	return (1);
}

void	load_textures_2(t_game *g)
{
	int		cell;
	int		bpp;
	int		size;
	int		endian;

	g->txt[7].img = mlx_xpm_file_to_image(g->mlx, g->t_sprite, &cell, &cell);
	g->txt[7].data = mlx_get_data_addr(g->txt[7].img, &bpp, &size, &endian);
	g->txt[8].img = mlx_xpm_file_to_image(g->mlx, g->t_sprite, &cell, &cell);
	g->txt[8].data = mlx_get_data_addr(g->txt[8].img, &bpp, &size, &endian);
	g->txt[9].img = mlx_xpm_file_to_image(g->mlx, g->t_sprite, &cell, &cell);
	g->txt[9].data = mlx_get_data_addr(g->txt[9].img, &bpp, &size, &endian);
	g->txt[10].img = mlx_xpm_file_to_image(g->mlx, SCREEN_1, &cell, &cell);
	g->txt[10].data = mlx_get_data_addr(g->txt[10].img, &bpp, &size, &endian);
	g->txt[11].img = mlx_xpm_file_to_image(g->mlx, SLAB, &cell, &cell);
	g->txt[11].data = mlx_get_data_addr(g->txt[11].img, &bpp, &size, &endian);
	g->txt[12].img = mlx_xpm_file_to_image(g->mlx, SCREEN_W, &cell, &cell);
	g->txt[12].data = mlx_get_data_addr(g->txt[12].img, &bpp, &size, &endian);
	g->txt[13].img = mlx_xpm_file_to_image(g->mlx, SCREEN_D, &cell, &cell);
	g->txt[13].data = mlx_get_data_addr(g->txt[13].img, &bpp, &size, &endian);
}

void	load_textures(t_game *g)
{
	int		cell;
	int		bpp;
	int		size;
	int		endian;

	g->txt[0].img = mlx_xpm_file_to_image(g->mlx, g->t_north, &cell, &cell);
	g->txt[0].data = mlx_get_data_addr(g->txt[0].img, &bpp, &size, &endian);
	g->txt[1].img = mlx_xpm_file_to_image(g->mlx, g->t_south, &cell, &cell);
	g->txt[1].data = mlx_get_data_addr(g->txt[1].img, &bpp, &size, &endian);
	g->txt[2].img = mlx_xpm_file_to_image(g->mlx, g->t_east, &cell, &cell);
	g->txt[2].data = mlx_get_data_addr(g->txt[2].img, &bpp, &size, &endian);
	g->txt[3].img = mlx_xpm_file_to_image(g->mlx, g->t_west, &cell, &cell);
	g->txt[3].data = mlx_get_data_addr(g->txt[3].img, &bpp, &size, &endian);
	g->txt[5].img = mlx_xpm_file_to_image(g->mlx, g->t_sprite, &cell, &cell);
	g->txt[5].data = mlx_get_data_addr(g->txt[5].img, &bpp, &size, &endian);
	(g->txt[0].bpp) = bpp;
	(g->txt[0].size) = size;
	if (g->bonus)
	{
		g->txt[6].img = mlx_xpm_file_to_image(g->mlx, g->t_sky, &cell, &cell);
		g->txt[6].data = mlx_get_data_addr(g->txt[6].img, &bpp, &size, &endian);
		g->txt[4].img = mlx_xpm_file_to_image(g->mlx, g->t_floor, &cell, &cell);
		g->txt[4].data = mlx_get_data_addr(g->txt[4].img, &bpp, &size, &endian);
		load_textures_2(g);
	}
}

void	init_player(t_game *gd)
{
	int i;
	int j;
	int b;

	i = 0;
	j = 0;
	b = 1;
	while (i < gd->map_size_y && b)
	{
		j = 0;
		while (j < gd->map_size_x && b)
		{
			if (ft_inset_c(gd->map[i][j], "NEWS"))
				b = 0;
			j = j + b;
		}
		i = i + b;
	}
	gd->p_x = CELL * j + CELL / 2;
	gd->p_y = CELL * i + CELL / 2;
	gd->p_t = gd->map[i][j] == 'E' ? 0 : 270;
	gd->p_t = gd->map[i][j] == 'N' ? 90 : gd->p_t;
	gd->p_t = gd->map[i][j] == 'W' ? 180 : gd->p_t;
	gd->p_h = 53;
}

void	init_game(t_game *game, char *map_name)
{
	int		i;

	i = 0;
	game->fr = 0;
	game->frgun = 0;
	read_map(game, map_name);
	init_player(game);
	game->p_tmax = ((game->p_t + TETA / 2) % 360) * RAD;
	game->p_tmin = ((game->p_t + TETA / 1) % 360) * RAD;
	check_files(game);
	load_textures(game);
	while (i < 256 && game->bonus)
	{
		if (game->frc[i] > 0)
			load_frames_type(game, i, game->frc[i]);
		i++;
	}
}
