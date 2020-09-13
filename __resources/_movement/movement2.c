/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 11:01:50 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/26 11:01:50 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

int		straffe(t_game *g, int dir)
{
	int		x;
	int		y;
	char	c;

	dir = dir == DDD ? 1 : -1;
	x = g->p_x + dir * (SPEED + 5) * sin(g->p_t * RAD);
	y = g->p_y + dir * (SPEED + 5) * -cos(g->p_t * RAD);
	c = g->map[y / CELL][x / CELL];
	if (c == '1' || c == '3')
		return (0);
	x = g->p_x + dir * (SPEED) * sin(g->p_t * RAD);
	y = g->p_y + dir * (SPEED) * cos(g->p_t * RAD);
	g->p_x = x;
	g->p_y = y;
	return (1);
}

int		move(t_game *g, int dir)
{
	int		x;
	int		y;
	char	c;

	x = g->p_x;
	y = g->p_y;
	x += dir * (SPEED + 10) * cos(g->p_t * RAD);
	y += dir * (SPEED + 10) * -sin(g->p_t * RAD);
	c = g->map[y / CELL][x / CELL];
	if (c == '1' || c == '3')
		return (0);
	x = g->p_x;
	y = g->p_y;
	x += dir * (SPEED + 5) * cos(g->p_t * RAD);
	y += dir * (SPEED + 5) * -sin(g->p_t * RAD);
	g->p_x = x;
	g->p_y = y;
	return (1);
}
