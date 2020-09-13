/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:36:53 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/26 11:36:53 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*format_data_x(char *d, t_params p, int neg)
{
	char	*r;

	r = ft_strdup(d);
	free(d);
	if (ft_len(d) != 0)
	{
		while (p.hpoint && p.point > ft_len(r))
			r = char_join_and_free(r, '0');
		r = p.hpoint && neg < 0 ? char_join_and_free(r, '-') : r;
	}
	while (p.hzero && p.zero > ft_len(r))
		r = char_join_and_free(r, p.hpoint ? ' ' : '0');
	r[0] = r[0] == '0' && neg < 0 ? '-' : r[0];
	while (p.hhyphen && p.hyphen > ft_len(r))
		r = join_char_and_free(r, ' ');
	while (p.hwidth && !p.hhyphen && p.width > 0 && p.width > ft_len(r))
		r = char_join_and_free(r, ' ');
	while (p.hwidth && !p.hhyphen && p.width < 0 && -p.width > ft_len(r))
		r = join_char_and_free(r, ' ');
	return (r);
}

int			parse_x(const char *format, va_list a)
{
	long int	i;
	char		*result;
	long int	data;
	t_params	p;

	p = read_params(format + 1, 'x', a);
	update_params(&p, 'x');
	data = va_arg(a, unsigned int);
	if (data == 0 && p.hpoint && p.point == 0)
		result = NULL;
	else
		result = u_int_to_hexa(data, 'a', 2);
	if (p.invalid != -1)
	{
		free(result);
		result = ft_strdup_to_c(format + p.invalid + 1, 'x');
	}
	result = format_data_x(result, p, 1);
	i = ft_len(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (i);
}

int			parse_xm(const char *format, va_list a)
{
	long int	i;
	char		*result;
	long int	data;
	t_params	p;

	p = read_params(format + 1, 'X', a);
	update_params(&p, 'X');
	data = va_arg(a, unsigned int);
	if (data == 0 && p.hpoint && p.point == 0)
		result = NULL;
	else
		result = u_int_to_hexa(data, 'A', 2);
	if (p.invalid != -1)
	{
		free(result);
		result = ft_strdup_to_c(format + p.invalid + 1, 'X');
	}
	result = format_data_x(result, p, 1);
	i = ft_len(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (i);
}
