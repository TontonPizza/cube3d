/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 02:42:49 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/22 02:42:49 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void		set_time_variables(t_game *g)
{
	g->current_frame_time = clock();
	g->delta_time = (double)(g->current_frame_time - g->last_frame_time);
	g->delta_time = g->delta_time / 100000;
	g->last_frame_time = g->current_frame_time;
	g->fr = (g->fr + g->delta_time);
}
