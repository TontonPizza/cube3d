/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:57:11 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/10/07 15:57:11 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** if s is "", should i return an array  containing "" or null ?
*/

#include "libft.h"

static int		ft_nbrsubstr(const char *s, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char		**ft_special_case(char **res, const char *s)
{
	res[0] = ft_strdup(s);
	res[1] = 0;
	return (res);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	int		start;
	int		end;
	int		i_tab;

	start = 0;
	end = 0;
	i_tab = 0;
	if (!(res = (char **)malloc(sizeof(char *) * (ft_nbrsubstr(s, c) + 1))))
		return (0);
	while (i_tab != ft_nbrsubstr(s, c))
	{
		while (s[start] == c)
			start++;
		if (!s[start])
			return (ft_special_case(res, s));
		end = start;
		while (s[end] != c && s[end])
			end++;
		res[i_tab] = ft_substr(s, start, (end - start));
		i_tab++;
		start = end;
	}
	res[i_tab] = 0;
	return (res);
}
