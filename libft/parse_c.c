/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:55:53 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/26 10:55:53 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			format_data_c(char *d, t_params p, int len)
{
	int		i;
	int		count;

	i = 0;
	count = len;
	while (p.hzero && p.zero > count && 1 + 0 * (count++))
		i += write(1, "0", 1);
	while (p.hpoint && p.point > count && 1 + 0 * (count++))
		i += write(1, "0", 1);
	while (p.hwidth && p.width > count && 1 + 0 * (count++))
		i += write(1, " ", 1);
	i += write(1, d, len);
	while (p.hwidth && p.width < 0 && -p.width > count && 1 + 0 * (count++))
		i += write(1, " ", 1);
	while (p.hhyphen && p.hyphen < 0 && -p.hyphen > count && 1 + 0 * (count++))
		i += write(1, " ", 1);
	while (p.hhyphen && p.hyphen > count && 1 + 0 * (count++))
		i += write(1, " ", 1);
	return (count);
}

int			parse_c(const char *format, va_list a)
{
	char		data;
	t_params	p;
	char		*result;
	int			i;

	p = read_params(format + 1, 'c', a);
	data = va_arg(a, int);
	data = (unsigned char)data;
	result = malloc(sizeof(char) * 2);
	result[0] = data;
	result[1] = 0;
	if (p.invalid != -1)
	{
		free(result);
		result = ft_strdup_to_c(format + p.invalid + 1, 'c');
	}
	else
		result[0] = data;
	i = ft_strlen(result);
	i = format_data_c(result, p, i == 0 ? 1 : i);
	free(result);
	return (i);
}
