/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:50:49 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/19 20:50:49 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					is_legal_char(char c, char d)
{
	if (ft_isdigit(c) && c != '0')
		return (-1);
	if (c != '0' && c != '-' && c != '*' && c != '.' && c != d)
		return (0);
	return (1);
}

void				init_param(t_params *t)
{
	t->point = 0;
	t->zero = 0;
	t->hyphen = 0;
	t->width = 0;
	t->hhyphen = 0;
	t->hpoint = 0;
	t->hwidth = 0;
	t->hzero = 0;
	t->invalid = -1;
}

void				update_params(t_params *t, char c)
{
	if (t->hhyphen == 1)
	{
		t->hyphen = t->zero > t->hyphen && t->hzero ? t->zero : t->hyphen;
		t->zero = 0;
		t->hzero = 0;
	}
	if (t->hwidth && t->width < 0)
		t->hyphen = -t->width;
	if (t->hhyphen == 0 && t->zero < 0 && t->hzero)
	{
		t->hhyphen = 1;
		t->hyphen = -t->zero;
		t->hzero = 0;
	}
	if (t->hpoint && t->point < 0 && c != 's')
		t->hpoint = 0;
	t->hyphen = t->hyphen < 0 ? -t->hyphen : t->hyphen;
}

t_params			read_params(const char *f, char c, va_list arg)
{
	t_params		r;
	int				k;

	k = 0;
	init_param(&r);
	while (f[k] != c && r.invalid == -1)
	{
		if (k == 0 && f[k] != '0' && ft_isdigit(f[k]))
			read_width_0(f, &r, &k);
		if (f[k] == '0')
			read_zero(f + k, &r, &k, arg);
		if (f[k] == '-')
			read_hyphen(f + k, &r, &k, arg);
		if (f[k] == '.')
			read_point(f + k, &r, &k, arg);
		if (f[k] == '*')
			read_width(f + k, &r, &k, arg);
		if (is_legal_char(f[k], c) == 0)
			r.invalid = k;
		if (is_legal_char(f[k], c) == -1)
			k++;
	}
	return (r);
}
