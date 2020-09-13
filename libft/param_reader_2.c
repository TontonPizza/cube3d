/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_reader_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:52:48 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/19 21:52:48 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		read_zero(const char *f, t_params *t, int *k, va_list arg)
{
	if (f[1] == '*')
	{
		t->zero = va_arg(arg, int);
		*k = *k + 2;
	}
	else
		t->zero = vo_atoi(f + 1, k);
	t->hzero = 1;
}

void		read_hyphen(const char *f, t_params *t, int *k, va_list arg)
{
	if (f[1] == '*')
	{
		t->hyphen = va_arg(arg, int);
		*k = *k + 2;
	}
	else
		t->hyphen = vo_atoi(f + 1, k);
	t->hhyphen = 1;
}

void		read_point(const char *f, t_params *t, int *k, va_list arg)
{
	int p;

	if (f[1] == '*')
	{
		t->point = va_arg(arg, int);
		*k = *k + 2;
		t->hpoint = 2;
	}
	else
	{
		p = vo_atoi(f + 1, k);
		if (t->hpoint != 2)
		{
			t->point = p;
			t->hpoint = 1;
		}
	}
}

void		read_width(const char *f, t_params *t, int *k, va_list arg)
{
	t->width = va_arg(arg, int);
	*k = *k + 1;
	t->hwidth = 1;
	t->hzero = 0 + f[0] * 0;
	if (t->hhyphen == 1)
		t->hyphen = t->width;
}

void		read_width_0(const char *f, t_params *t, int *k)
{
	t->hwidth = 1;
	t->width = vo_atoi(f, k);
	t->hzero = 0;
	if (t->hhyphen == 1)
		t->hyphen = t->width;
	*k = *k - 1;
}
