/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:22:45 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/23 04:22:45 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void	load_frames_type(t_game *g, char tp, int frame_count)
{
	int		f;
	int		i;
	char	*txt;
	char	*nb;

	i = 0;
	while (i < frame_count)
	{
		nb = ft_itoa(i);
		txt = ft_strjoin(g->t_frame[(int)tp], nb);
		if (open(txt, O_RDONLY) <= 0)
			error_message("can't open file", g, 0);
		(g->spr[(int)tp])[i].img = mlx_xpm_file_to_image(g->mlx, txt, &f, &f);
		(g->spr[(int)tp])[i].data = mlx_get_data_addr(g->spr[(int)tp][i].img,
				&f, &f, &f);
		free(txt);
		free(nb);
		i++;
	}
}
