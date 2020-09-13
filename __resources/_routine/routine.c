/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 09:57:09 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/24 09:57:09 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void		teleport(t_game *g)
{
	int		x;
	int		y;

	x = g->p_x / 64;
	y = g->p_y / 64;
	if (x >= 0 && x < g->map_size_x && y >= 0 && y < g->map_size_y)
	{
		if (g->map[y][x] == '6')
		{
			g->p_x = CELL * 5;
			g->p_y = CELL * 5;
			g->room = 0;
			play_sound_1(g, "sounds/door.wav\n");
		}
	}
}

int			game_routine(t_game *g)
{
	if (g->game_state == GAME_STATE_INTRO)
		render_intro(g, 10);
	else if (g->game_state == GAME_STATE_MAZE)
	{
		if (g->image != NULL)
			mlx_destroy_image(g->mlx, g->image);
		check_damage(g);
		smooth_move(g);
		smooth_rotate(g);
		grab_bonus(g);
		grab_gun(g);
		teleport(g);
		reset_attack(g);
		render_scene_bonus(g);
		render_gui(g);
		if (g->is_shooting)
			g->frgun = g->frgun + 1 % 20;
		g->ending_screen = clock();
	}
	else if (g->game_state == GAME_STATE_WIN)
		render_outro(g, 12);
	else if (g->game_state == GAME_STATE_DEATH)
		render_intro(g, 13);
	return (put_image_and_destroy(g));
}

void		reset_attack(t_game *g)
{
	clock_t		now;

	now = clock();
	if (now - g->last_attack > COOL_DOWN / 2 && g->is_shooting == 1)
	{
		g->is_shooting = 0;
		g->last_attack = now;
		g->frgun = 0;
	}
}

void		check_damage(t_game *g)
{
	float		dist;
	clock_t		current;

	dist = ft_dist(g->p_x - g->boss_x, g->p_y - g->boss_y);
	if (dist < CELL * 2)
	{
		current = clock();
		if (current - g->last_hit > COOL_DOWN)
		{
			g->last_hit = current;
			g->player_hp = ft_max(g->player_hp - 1, 0);
			play_sound_1(g, "sounds/hit1.wav\n");
		}
	}
	if (g->player_hp <= 1)
	{
		g->game_state = GAME_STATE_DEATH;
		play_sound_1(g, "sounds/kill.wav\n");
	}
	if (g->boss_hp <= 1)
	{
		g->game_state = GAME_STATE_WIN;
		play_sound_1(g, "sounds/notomorrow.wav\n");
	}
}

void		grab_gun(t_game *g)
{
	int		x;
	int		y;

	x = g->p_x / 64;
	y = g->p_y / 64;
	if (x >= 0 && x < g->map_size_x && y >= 0 && y < g->map_size_y)
	{
		if (g->map[y][x] == SWORD_SPRITE)
		{
			g->player_gun = 1;
			g->map[y][x] = FLOOR_SPRITE;
		}
	}
}
