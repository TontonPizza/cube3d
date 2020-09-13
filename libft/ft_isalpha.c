/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:03:43 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/10/09 16:03:43 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int		ft_inset_s(char *c, char *set)
{
	int		v[255];
	int		i;

	i = 0;
	while (i < 255)
		v[i++] = 0;
	i = 0;
	while (set[i])
		v[(int)set[i++]]++;
	i = 0;
	while (c[i])
	{
		if (v[(int)c[i++]] == 0)
			return (0);
	}
	return (1);
}

int		ft_inset_c(char c, char *set)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(set);
	while (i < len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
