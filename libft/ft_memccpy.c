/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:18:34 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/10/09 09:18:34 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** test ok
*/

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const char		*s;
	char			*d;
	size_t			i;

	i = 0;
	s = src;
	d = dest;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i++] == c)
		{
			return (dest + i);
		}
	}
	return (NULL);
}
