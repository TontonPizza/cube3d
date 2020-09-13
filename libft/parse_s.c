/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:19:57 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/26 11:19:57 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*format_data_s0(t_params p)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_strdup("");
	i = ft_len(result);
	while (p.hzero && p.zero > ft_len(result))
		result = char_join_and_free(result, p.hpoint ? ' ' : '0');
	while (p.hhyphen && p.hyphen > i && 1 + 0 * (i++))
		result = join_char_and_free(result, ' ');
	while (p.hwidth && p.width > i && 1 + 0 * (i++))
		result = char_join_and_free(result, ' ');
	while (p.hwidth && -p.width > i && 1 + 0 * (i++))
		result = join_char_and_free(result, ' ');
	return (result);
}

char		*format_data_s(char *d, t_params p)
{
	char	*result;
	int		i;

	result = ft_strdup(d);
	i = ft_len(result);
	free(d);
	if (p.hpoint && p.point >= 0)
		result[p.point >= 0 && p.point < i ? p.point : i] = 0;
	i = ft_len(result);
	if (i == 0)
	{
		free(result);
		return (format_data_s0(p));
	}
	while (p.hzero && p.zero > ft_len(result))
		result = char_join_and_free(result, p.hpoint ? ' ' : '0');
	while (p.hhyphen && p.hyphen > i && 1 + 0 * (i++))
		result = join_char_and_free(result, ' ');
	while (p.hwidth && p.width > i && 1 + 0 * (i++))
		result = char_join_and_free(result, ' ');
	while (p.hwidth && -p.width > i && 1 + 0 * (i++))
		result = join_char_and_free(result, ' ');
	return (result);
}

int			parse_s(const char *format, va_list a)
{
	t_params	params;
	char		*result;
	int			i;

	params = read_params(format + 1, 's', a);
	update_params(&params, 's');
	result = vo_strdup_2(va_arg(a, char*));
	result = format_data_s(result, params);
	i = ft_len(result);
	ft_putstr_fd(result, 1);
	free(result);
	return (i);
}
