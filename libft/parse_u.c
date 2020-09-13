/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:30:04 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/26 11:30:04 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*format_data_u(char *d, t_params p)
{
	char	*r;

	r = ft_strdup(d);
	free(d);
	if (ft_len(d) != 0)
	{
		while (p.hpoint && p.point > ft_len(r))
			r = char_join_and_free(r, '0');
	}
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

int			parse_u(const char *format, va_list a)
{
	long int			data;
	char				*result;
	t_params			p;
	int					i;

	p = read_params(format + 1, 'u', a);
	update_params(&p, 'u');
	data = va_arg(a, unsigned int);
	if (data == 0 && p.hpoint && p.point == 0)
		result = NULL;
	else
		result = ft_itoa(data);
	if (p.invalid != -1)
	{
		free(result);
		result = ft_strdup_to_c(format + p.invalid + 1, 'u');
	}
	result = format_data_u(result, p);
	i = ft_len(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (i);
}
