/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:49:43 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/10/09 15:49:43 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*source;

	source = (char *)s;
	i = 0;
	while (i < n)
	{
		if (source[i] == c)
			return (source + i);
		i++;
	}
	return (NULL);
}
