/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:39:48 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/10/07 15:39:48 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** tests ok
** chaines vides
** indice supperieur a strlen s
** len supp > strlen
** len  = 0
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		end;

	end = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start > ft_strlen(s))
	{
		dest[0] = '\0';
		return (dest);
	}
	while (((len - end) > 0) && s[start + end])
	{
		dest[end] = s[start + end];
		end++;
	}
	dest[end] = '\0';
	return (dest);
}
