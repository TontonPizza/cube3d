/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:33:36 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/10/08 15:33:36 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void		ft_display(long int i, int fd)
{
	int tmp;

	if ((i / 10) > 0)
		ft_display((i / 10), fd);
	tmp = (i % 10) + 48;
	ft_putchar_fd(tmp, fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	long int		i;

	i = n;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = -n;
	}
	ft_display(i, fd);
}
