/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:41:41 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/06 15:41:41 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				is_a_valid_flag(char c)
{
	int		i;
	int		k;
	char	*t;

	t = "cspdiuxX%";
	i = 0;
	k = ft_strlen(t);
	while (i < k)
	{
		if (c == t[i])
			return (1);
		i++;
	}
	return (0);
}

void			init_flag(int (*f[255])(const char *, va_list))
{
	f['\0'] = &parse_zero;
	f['d'] = &parse_d;
	f['p'] = &parse_p;
	f['c'] = &parse_c;
	f['s'] = &parse_s;
	f['u'] = &parse_u;
	f['i'] = &parse_i;
	f['x'] = &parse_x;
	f['X'] = &parse_xm;
	f['%'] = &parse_pc;
}

int				parse_flags(const char *f, va_list a, int *c)
{
	static int		(*parsers[255])(const char *, va_list);
	int				k;

	if (parsers['d'] == NULL)
		init_flag(parsers);
	k = 1;
	while (f[k] && !is_a_valid_flag(f[k]))
		k++;
	*c = *c + parsers[(int)f[k]](f, a);
	return (k + 1);
}
