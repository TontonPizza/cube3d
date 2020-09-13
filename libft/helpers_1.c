/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:44:59 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/06 16:44:59 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int			vo_atoi(const char *str, int *count)
{
	char		*start;
	int			s;
	long int	result;
	int			i;

	i = 0;
	result = 0;
	while (str[i] == ' ')
		i++;
	s = str[i] == '-' ? -1 : 1;
	start = s == -1 ? (char *)str + (i + 1) : (char *)str + i;
	if (str[i] == '-')
		*count = *count + 1;
	while (start[i] && ft_isdigit(start[i]))
	{
		result = result * 10 + start[i] - '0';
		i++;
	}
	*count = *count + i + 1;
	return (result * s);
}

char				*u_int_to_hexa(unsigned int i, char alpha, int mode)
{
	char				result[101];
	unsigned int		remains;
	int					k;

	if (i == 0)
		return (mode == 2 ? ft_strdup("0") : ft_strdup("0x0"));
	k = 0;
	remains = 0;
	result[100] = '\0';
	while (i != 0)
	{
		remains = i % 16;
		if (remains < 10)
			result[99 - (k++)] = '0' + remains;
		else if (remains >= 10)
			result[99 - (k++)] = alpha + remains - 10;
		i = i / 16;
	}
	result[99 - (k++)] = 'X' - 'A' + alpha;
	result[99 - (k++)] = '0';
	return (vo_strdup(result + 100 - k + mode));
}

char				*long_int_to_hexa(long int i, char alpha, int mode)
{
	char				result[101];
	long int			remains;
	int					k;

	if (i == 0)
		return (ft_strdup("0"));
	k = 0;
	remains = 0;
	result[100] = '\0';
	while (i != 0)
	{
		remains = i % 16;
		if (remains < 10)
			result[99 - (k++)] = '0' + remains;
		else if (remains >= 10)
			result[99 - (k++)] = alpha + remains - 10;
		i = i / 16;
	}
	result[99 - (k++)] = 'X' - 'A' + alpha;
	result[99 - (k++)] = '0';
	return (vo_strdup(result + 100 - k + mode));
}

void				free_many(char *s1, char *s2)
{
	free(s1);
	free(s2);
}
