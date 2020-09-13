/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:33:20 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/10/10 10:33:20 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*result;
	int		i;

	i = 0;
	if (!(result = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = (char)s1[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char		*ft_strdup_to_c(const char *s1, char c)
{
	char	*result;
	int		i;

	i = 0;
	if (!(result = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1 && s1[i] && s1[i] != c)
	{
		result[i] = (char)s1[i];
		i++;
	}
	if (s1 && s1[i] == c)
		result[i++] = c;
	result[i] = 0;
	return (result);
}

char		*vo_strdup_2(const char *s1)
{
	char	*result;
	int		i;

	if (s1 == NULL)
	{
		result = ft_strdup("(null)");
		return (result);
	}
	i = 0;
	if (!(result = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = (char)s1[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char		*vo_strdup(const char *s1)
{
	char	*result;
	int		i;

	i = 0;
	if (!(result = malloc(sizeof(char) * 50)))
		return (NULL);
	while (s1[i])
	{
		result[i] = (char)s1[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
