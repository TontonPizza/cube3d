/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:14:55 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/26 11:14:55 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*format_data_pc(char *d, t_params p)
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

int			parse_pc(const char *format, va_list a)
{
	int			i;
	char		*result;
	t_params	params;

	params = read_params(format + 1, '%', a);
	update_params(&params, '%');
	result = ft_strdup("%");
	if (params.invalid != -1)
	{
		free(result);
		result = ft_strdup_to_c(format + params.invalid + 1, '%');
		result[ft_len(result) - 1] = 0;
	}
	else
		result = format_data_pc(result, params);
	i = ft_len(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (i);
}
