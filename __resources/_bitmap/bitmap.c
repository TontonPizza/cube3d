/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 04:01:04 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/21 04:01:04 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void		write_header_2(char *file, int x, int y)
{
	file[0x1c] = 0x18;
	file[0x1d] = 0;
	ft_memcpy(file + 0x1e, "\0\0\0\0", sizeof(char) * 4);
	file[0x22] = (x * y) % 256;
	file[0x23] = ((x * y) / 256) % 256;
	file[0x24] = (((x * y) / 256) / 256) % 256;
	file[0x25] = ((((x * y) / 256) / 256) / 256) % 256;
	file[0x26] = 0x13;
	file[0x27] = 0x0b;
	ft_memcpy(file + 0x28, "\0\0", sizeof(char) * 2);
	file[0x2a] = 0x13;
	file[0x2b] = 0x0b;
	ft_memcpy(file + 0x2c, "\0\0", sizeof(char) * 2);
	ft_memcpy(file + 0x2e, "\0\0\0\0\0\0\0\0", sizeof(char) * 8);
}

void		write_header(char *file, int x, int y)
{
	int size;

	size = x * y * 3;
	file[0] = 'B';
	file[1] = 'M';
	file[2] = (size + 54) % 256;
	file[3] = ((size + 54) / 256) % 256;
	file[4] = (((size + 54) / 256) / 256) % 256;
	file[5] = ((((size + 54) / 256) / 256) / 256) % 256;
	ft_memcpy(file + 6, "\0\0\0\0", sizeof(char) * 4);
	file[0xa] = 54;
	ft_memcpy(file + 0xb, "\0\0\0", sizeof(char) * 4);
	file[0xe] = 40;
	ft_memcpy(file + 0xf, "\0\0\0", sizeof(char) * 4);
	file[0x12] = (x) % 256;
	file[0x13] = ((x) / 256) % 256;
	file[0x14] = (((x) / 256) / 256) % 256;
	file[0x15] = ((((x) / 256) / 256) / 256) % 256;
	file[0x16] = (y) % 256;
	file[0x17] = ((y) / 256) % 256;
	file[0x18] = (((y) / 256) / 256) % 256;
	file[0x19] = ((((y) / 256) / 256) / 256) % 256;
	file[0x1a] = 1;
	file[0x1b] = 0;
	write_header_2(file, x, y);
}

void		write_data(char *file, t_game *g)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 54;
	y = g->screen_y;
	while (y--)
	{
		x = -1;
		while (++x < g->screen_x)
		{
			j = x * 4 + y * g->screen_x * 4;
			file[i++] = ((unsigned char *)(g->data))[j++];
			file[i++] = ((unsigned char *)(g->data))[j++];
			file[i++] = ((unsigned char *)(g->data))[j];
		}
	}
}

void		write_bmp(char *file_name, t_game *g)
{
	int		fd;
	int		size;
	char	*file;

	size = g->screen_y * g->screen_x * 3;
	fd = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0777);
	if (!(file = malloc(sizeof(char) * (size + 54))))
		error_message("malloc error", g, 1 + g->bonus);
	write_header(file, g->screen_x, g->screen_y);
	write_data(file, g);
	write(fd, file, size + 54);
	free(file);
	close(fd);
}
