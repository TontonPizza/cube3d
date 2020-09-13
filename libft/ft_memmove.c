/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:35:53 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/10/09 15:35:53 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		buffer[n];
	char		*destcpy;
	char		*source;

	source = (char *)src;
	destcpy = dest;
	i = 0;
	while (i < n)
	{
		buffer[i] = source[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		destcpy[i] = buffer[i];
		i++;
	}
	return (dest);
}
