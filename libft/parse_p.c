/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:59:05 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/26 10:59:05 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*format_data_p(char *d, t_params p)
{
	char	*r;

	r = ft_strdup(d);
	free(d);
	if (p.invalid != -1)
		return (r);
	if (ft_len(d) != 0)
	{
		while (p.hpoint && p.point > ft_len(r))
			r = char_join_and_free(r, '0');
	}
	r = char_join_and_free(r, 'x');
	r = char_join_and_free(r, '0');
	while (p.hzero && p.zero > ft_len(r))
		r = char_join_and_free(r, p.hpoint ? ' ' : '0');
	while (p.hhyphen && p.hyphen > ft_len(r))
		r = join_char_and_free(r, ' ');
	while (p.hwidth && !p.hhyphen && p.width > 0 && p.width > ft_len(r))
		r = char_join_and_free(r, ' ');
	while (p.hwidth && !p.hhyphen && p.width < 0 && -p.width > ft_len(r))
		r = join_char_and_free(r, ' ');
	return (r);
}

int			parse_p(const char *format, va_list a)
{
	long int	i;
	char		*result;
	long int	data;
	t_params	p;

	p = read_params(format + 1, 'p', a);
	update_params(&p, 'p');
	data = va_arg(a, long int);
	if (data == 0 && p.hpoint && p.point == 0)
		result = ft_strdup("");
	else
		result = long_int_to_hexa(data, 'a', 2);
	if (p.invalid != -1)
	{
		free(result);
		result = ft_strdup_to_c(format + p.invalid + 1, 'p');
	}
	result = format_data_p(result, p);
	i = ft_len(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (i);
}
