/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_sound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 22:43:36 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/28 22:43:36 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void		play_sound_1(t_game *g, char *sound)
{
	pthread_create(&(g->thread), NULL, &play_sound, sound);
}

void		*play_sound(void *arg)
{
	char		*sound;
	char		command[255];

	sound = (char *)(arg);
	ft_memcpy(command, "aplay --channels=1 ", 6);
	ft_memcpy(command + 6, sound, ft_strlen(sound));
	system(command);
	return (NULL);
}
