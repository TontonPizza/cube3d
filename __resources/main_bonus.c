/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 10:45:47 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/20 10:45:47 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../____includes/cube3d.h"

void	set_g_const_2(t_game *g)
{
	int osef;

	g->bonus = 1;
	g->bonus_count = 0;
	g->move_rotate = 0;
	g->move_forward = 0;
	g->player_gun = 0;
	g->is_shooting = 0;
	g->game_state = GAME_STATE_INTRO;
	g->last_frame_time = clock();
	g->last_move = g->last_frame_time;
	g->last_rotate = g->last_move;
	g->player_hp = HP_MAX;
	g->boss_hp = 8;
	g->last_hit = clock();
	g->last_attack = g->last_hit;
	g->ef = 0;
}

void	set_g_const(t_game *g)
{
	int i;

	i = 0;
	while (i < 256)
		g->frc[i++] = -1;
	g->frc[CRYSTAL_SPRITE] = 1;
	g->t_frame[CRYSTAL_SPRITE] = "./textures/bonus/health";
	g->frc[TRIANGLE_SPRITE] = 31;
	g->t_frame[TRIANGLE_SPRITE] = "./textures/bonus/sprite/trg/triangle";
	g->frc[SWORD_SPRITE] = 12;
	g->t_frame[SWORD_SPRITE] = "./textures/bonus/sprite/sword/sword";
	g->frc['B'] = 8;
	g->t_frame['B'] = "./textures/bonus/sprite/minotaurus/minotaurus_";
	g->frc['A'] = 5;
	g->t_frame['A'] = "./textures/bonus/sprite/minotaurus/attack";
	g->frc['G'] = 5;
	g->t_frame['G'] = "./textures/bonus/sprite/sword/sword_hand";
	g->frc['6'] = 1;
	g->t_frame['6'] = "./textures/bonus/sprite/portal";
	g->t_floor = "./textures/bonus/sol_neon.xpm";
	g->t_sky = "./textures/bonus/ark1024x256.xpm";
	set_g_const_2(g);
}

int		main(int argc, char **argv)
{
	t_game game;

	set_g_const(&game);
	game.mlx = mlx_init();
	init_game(&game, "maps/map_bonus.cub");
	init_boss(&game);
	display_map(&game);
	game.room = 1;
	game.window = mlx_new_window(game.mlx, game.screen_x, game.screen_y,
			"Quest for the Crown");
	set_hookers(&game);
	mlx_loop_hook(game.mlx, &game_routine, &game);
	mlx_loop(game.mlx);
	return (argc + argv[0][0]);
}
