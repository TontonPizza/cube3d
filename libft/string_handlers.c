/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:58:37 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/11/06 15:58:37 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*join_char_and_free(char *str, char c)
{
	int		i;
	char	*result;

	i = 0;
	if (!(result = malloc(sizeof(char) * (ft_len(str) + 2))))
	{
		free(str);
		return (NULL);
	}
	while (str && str[i] != 0)
	{
		result[i] = str[i];
		i++;
	}
	result[i++] = c;
	result[i] = 0;
	free(str);
	return (result);
}

char		*char_join_and_free(char *str, char c)
{
	int		i;
	char	*result;

	i = 0;
	if (!(result = malloc(sizeof(char) * (ft_len(str) + 2))))
	{
		free(str);
		return (NULL);
	}
	result[0] = c;
	while (str && str[i] != 0)
	{
		result[i + 1] = str[i];
		i++;
	}
	result[i + 1] = 0;
	free(str);
	return (result);
}

char		*ft_strjoin_and_free(char *t1, char *t2)
{
	char		*result;
	int			i;
	int			k;

	if (!(result = malloc(sizeof(char) * (ft_len(t1) + ft_len(t2) + 1))))
	{
		free(t1);
		return (NULL);
	}
	i = 0;
	k = 0;
	while (t1 && t1[i])
	{
		result[i] = t1[i];
		i++;
	}
	while (t2 && t2[k])
	{
		result[i + k] = t2[k];
		k++;
	}
	result[i + k] = 0;
	free(t1);
	return (result);
}
