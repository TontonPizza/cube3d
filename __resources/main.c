/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 02:42:29 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/12 02:42:29 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../____includes/cube3d.h"

int		rotate(int keycode, void *params)
{
	int		angle;
	t_game	*game;

	angle = 0;
	game = (t_game*)params;
	if (keycode == LEFT)
		angle += 10;
	else if (keycode == RIGHT)
		angle += 350;
	else if (keycode == ZZZ)
		move(game, 1);
	else if (keycode == SSS)
		move(game, -1);
	else if (keycode == QQQ || keycode == DDD)
		straffe(game, keycode);
	else if (keycode == ESC)
		destroy_game_data(game);
	angle = angle % 360;
	game->p_t += angle;
	return (0);
}

int		main(int argc, char **argv)
{
	t_game game;

	game.bonus = 0;
	game.mlx = mlx_init();
	init_game(&game, argv[1]);
	display_map(&game);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6) == 0)
		render_bitmap(&game);
	game.window = mlx_new_window(game.mlx, game.screen_x, game.screen_y,
			"look at me\0");
	mlx_key_hook(game.window, &rotate, &game);
	mlx_loop_hook(game.mlx, &render_scene, &game);
	mlx_loop(game.mlx);
	return (argc + argv[0][0]);
}
