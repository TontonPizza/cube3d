/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _movement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 10:42:47 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/20 10:42:47 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

int		controls(int keycode, void *params)
{
	t_game		*game;
	int			angle;

	game = (t_game*)params;
	if (game->game_state != GAME_STATE_MAZE && keycode != GO)
		return (0);
	mlx_do_key_autorepeaton(game->mlx);
	angle = game->p_t;
	if (keycode == QQQ || keycode == DDD)
		straffe(game, keycode);
	if (keycode == RIGHT || keycode == LEFT)
		angle += keycode == RIGHT ? 350 : 10;
	if (keycode == ZZZ || keycode == SSS)
		move(game, keycode == ZZZ ? 1 : -1);
	if (keycode == ESC)
		destroy_game_data_full(game, 1);
	if (keycode == SPACE)
		attack(game);
	if (keycode == GO && game->game_state == GAME_STATE_INTRO)
		game->game_state = GAME_STATE_MAZE;
	angle = angle % 360;
	game->p_t = angle;
	game->p_tmax = ((game->p_t + TETA / 2) % 360) * RAD;
	game->p_tmin = ((game->p_t + TETA / 1) % 360) * RAD;
	return (0);
}
