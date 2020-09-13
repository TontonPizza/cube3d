/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:37:06 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/10/09 22:37:06 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		k;

	k = 0;
	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (i < n && s1[i])
	{
		if (s1[i] == s2[0])
		{
			while (s1[i + k] == s2[k] && (i + k) < n)
				k++;
			if (k == ft_strlen(s2))
				return ((char*)(s1 + i));
			k = 0;
		}
		i++;
	}
	return (NULL);
}
