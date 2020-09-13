/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:58:42 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/10/10 09:58:42 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	char		*start;
	int			s;
	long int	result;
	int			i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
	|| str[i] == '\f' || str[i] == '\r')
		i++;
	result = 0;
	s = str[i] == '-' ? -1 : 1;
	start = s == -1 || str[i] == '+' ? (char *)str + (i + 1) : (char *)str + i;
	i = 0;
	while (ft_isdigit(start[i]))
	{
		result = result * 10 + start[i] - '0';
		i++;
	}
	return ((int)(result * s));
}
