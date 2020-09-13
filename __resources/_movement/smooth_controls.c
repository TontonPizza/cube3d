/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 04:30:24 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/28 04:30:24 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

int		smooth_rotate(t_game *game)
{
	int			angle;
	clock_t		now;

	now = clock();
	if (game->move_rotate == 0 || now - game->last_rotate < ROTATE_COOLDOWN)
		return (0);
	angle = game->p_t;
	angle += game->move_rotate * ANGULAR_SPEED;
	angle = angle % 360;
	game->p_t = angle;
	game->p_tmax = ((game->p_t + TETA / 2) % 360) * RAD;
	game->p_tmin = ((game->p_t + TETA / 1) % 360) * RAD;
	game->last_rotate = now;
	return (1);
}

int		smooth_move(t_game *g)
{
	int		x;
	int		y;
	char	c;
	clock_t	now;

	now = clock();
	if (g->move_forward == 0 || now - g->last_move < MOVE_COOLDOWN)
		return (0);
	x = g->p_x;
	y = g->p_y;
	x += g->move_forward * (SPEED + 10) * cos(g->p_t * RAD);
	y += g->move_forward * (SPEED + 10) * -sin(g->p_t * RAD);
	c = g->map[y / CELL][x / CELL];
	if (c == '1' || c == TRIANGLE_SPRITE)
		return (0);
	x = g->p_x;
	y = g->p_y;
	x += g->move_forward * (SPEED + 5) * cos(g->p_t * RAD);
	y += g->move_forward * (SPEED + 5) * -sin(g->p_t * RAD);
	g->p_x = x;
	g->p_y = y;
	g->last_move = now;
	return (1);
}

int		key_press_hook(int key, void *params)
{
	t_game *game;

	game = (t_game*)params;
	if (game->game_state == GAME_STATE_INTRO && key != GO)
		return (0);
	else if (key == GO && game->game_state == GAME_STATE_INTRO)
		game->game_state = GAME_STATE_MAZE;
	else if (key == ESC)
		destroy_game_data_full(game, 1);
	else if (key == SPACE)
		attack(game);
	else if (key == ZZZ || key == SSS)
		game->move_forward = key == ZZZ ? 1 : -1;
	else if (key == LEFT || key == RIGHT)
		game->move_rotate = key == LEFT ? 1 : 359;
	if (key == SPACE &&
		game->p_y / 64 == 36 && game->p_x / 64 == 2)
		game->map[37][2] = '0';
	return (0);
}

int		key_release_hook(int key, void *params)
{
	t_game *g;

	g = (t_game*)params;
	if (key == ZZZ || key == SSS)
		g->move_forward = 0;
	if (key == LEFT || key == RIGHT)
		g->move_rotate = 0;
	if (key == QQQ || key == DDD)
		g->move_straffe = 0;
	return (0);
}

void	set_hookers(t_game *g)
{
	mlx_hook(g->window, 2, (1L << 0), key_press_hook, g);
	mlx_hook(g->window, 3, (1L << 1), key_release_hook, g);
}
