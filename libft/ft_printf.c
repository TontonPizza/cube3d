/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:41:17 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/19 20:41:17 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vo_putchar_count(char c, int fd, int *count)
{
	write(fd, &c, 1);
	*count = *count + 1;
}

int		ft_printf(const char *format, ...)
{
	int			i;
	int			lf;
	int			count;
	va_list		args;

	va_start(args, format);
	i = 0;
	count = 0;
	lf = ft_strlen(format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			vo_putchar_count(format[i], 1, &count);
			i++;
		}
		if (format[i] == '%')
			i += parse_flags(format + i, args, &count);
		if (i >= lf)
			break ;
	}
	va_end(args);
	return (count);
}
