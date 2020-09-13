/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 00:31:27 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/28 00:31:27 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void			shadow(char *color, float dist, char *shade)
{
	int		i;
	float	coeff;

	if (SHADOW_MODE)
	{
		coeff = (1 - dist / SHADOW_MAX_DIST);
		coeff = coeff > 1 ? 1 : coeff;
		coeff = coeff < 0 ? 0 : coeff;
	}
	else
		coeff = 1;
	i = 0;
	while (i < 3)
	{
		shade[i] = (unsigned char)(color[i] * coeff);
		i++;
	}
	shade[3] = 255;
}
