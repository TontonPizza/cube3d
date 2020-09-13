/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:06:31 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/10/09 21:06:31 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;
	int		found;

	found = 0;
	result = (char *)s;
	i = 0;
	while (result[i])
	{
		if (result[i] == c)
		{
			found = i;
		}
		i++;
	}
	if (found > 0 || result[0] == c)
		return (result + found);
	if (result[i] == 0 && c == 0)
		return (result + i);
	return (NULL);
}
