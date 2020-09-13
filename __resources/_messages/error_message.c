/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 00:38:44 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/29 00:38:44 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

int		error_message(char *message, t_game *g, int mode)
{
	ft_printf("Error :\n%s\n", message);
	if (mode >= 1)
		destroy_game_data(g);
	if (mode >= 2)
	{
		mlx_destroy_image(g->mlx, g->image);
		mlx_destroy_window(g->mlx, g->window);
	}
	exit(0);
	return (-1);
}
