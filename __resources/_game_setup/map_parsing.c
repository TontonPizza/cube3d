/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 02:57:12 by vo-nguye          #+#    #+#             */
/*   Updated: 2019/12/12 02:57:12 by vo-nguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../____includes/cube3d.h"

void	read_resolution(char *line, t_game *game)
{
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	game->screen_x = ft_atoi(line + i);
	game->screen_x = ft_min(MAX_RES_X, game->screen_x);
	game->screen_x = ft_max(320, game->screen_x);
	while (ft_isdigit(line[i + 1]))
		i++;
	while (line[i] == ' ')
		i++;
	game->screen_y = ft_atoi(line + i + 1);
	game->screen_y = ft_min(MAX_RES_Y, game->screen_y);
	game->screen_y = ft_max(200, game->screen_y);
}

void	read_color(char *line, unsigned char *fc)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	fc[2] = (unsigned char)ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ',' || line[i] == ' ')
		i++;
	fc[1] = (unsigned char)ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ',' || line[i] == ' ')
		i++;
	fc[0] = (unsigned char)ft_atoi(line + i);
	fc[3] = 0;
}

void	read_line(char *line, t_game *game)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		read_resolution(line + 2, game);
	if (ft_strncmp(line, "NO ", 3) == 0)
		game->t_north = (ft_strtrim(line + 3, " "));
	if (ft_strncmp(line, "SO ", 3) == 0)
		game->t_south = (ft_strtrim(line + 3, " "));
	if (ft_strncmp(line, "WE ", 3) == 0)
		game->t_west = (ft_strtrim(line + 3, " "));
	if (ft_strncmp(line, "EA ", 3) == 0)
		game->t_east = (ft_strtrim(line + 3, " "));
	if (ft_strncmp(line, "S ", 2) == 0)
		game->t_sprite = (ft_strtrim(line + 2, " "));
	if (ft_strncmp(line, "F ", 2) == 0)
		read_color(line + 2, (game->floor));
	if (ft_strncmp(line, "C ", 2) == 0)
		read_color(line + 2, (game->ceiling));
}

char	*no_space_line(char *line)
{
	char *tmp;
	char *tmp2;
	char *result;

	tmp = line;
	if (!(result = malloc(sizeof(char) * ft_strlen(line))))
		return (NULL);
	tmp2 = result;
	while (*(line) != 0)
	{
		while (*(line) == ' ')
			line++;
		while (*(line) && *(line) != ' ')
			*(result++) = *(line++);
	}
	*(result) = 0;
	free(tmp);
	return (tmp2);
}

int		read_map(t_game *gd, char *m)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(m, O_RDONLY);
	i = 0;
	if (fd < 0 || gd == NULL)
		return (error_message("could not read file", gd, 0));
	if (ft_strlen(m) < 5 || ft_strncmp(m + ft_strlen(m) - 4, ".cub", 4) != 0)
		return (error_message("invalid map format", gd, 0));
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_inset_s(line, "1 ") == 1 && ft_strlen(line) > 2)
			break ;
		read_line(line, gd);
		free(line);
	}
	if (!(gd->map = malloc(sizeof(char *) * MAP_SIZE)))
		return (error_message("malloc error", gd, 0));
	gd->map[0 * (i++)] = no_space_line(line);
	while (get_next_line(fd, &line))
		gd->map[i++] = no_space_line(line);
	gd->map[i] = NULL;
	free(line);
	return (map_validator(gd) && map_validator_2(gd, i));
}
