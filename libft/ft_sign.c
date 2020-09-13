/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:22:20 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/05 14:22:20 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			sign(float a)
{
	if (a > 0)
		return (1);
	if (a < 0)
		return (-1);
	return (0);
}

int			ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int			ft_min(int a, int b)
{
	return (a > b ? b : a);
}
