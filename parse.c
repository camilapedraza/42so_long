/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:51:00 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/22 23:09:06 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *filepath)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (fd);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	return (count);
}

void	load_map(t_game *g, char *filepath)
{
	int		fd;
	int		y;
	char	*line;
	int		len;

	fd = open(filepath, O_RDONLY);
	if (fd > 0)
		g->map = malloc(sizeof(char *) * (g->map_h + 1));
	if (!g->map)
		exit_game(g);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		g->map[y++] = line;
	}
	if (y != g->map_h)
		exit_game(g);
	g->map[y] = NULL;
	close(fd);
}

void	validate_map(t_game *g)
{
	if (g->map_h < 3 || g->map_w < 3)
	{
		write(2, "Error: Map is too small\n", 25);
		exit_game(g);
	}
	if (!is_rectangle(g))
	{
		write(2, "Error: Map is not a rectangle\n", 31);
		exit_game(g);
	}
	if (!has_valid_objects(g))
		exit_game(g);
	if (!has_valid_border(g))
	{
		write(2, "Error: Map has break in boundary wall\n", 39);
		exit_game(g);
	}
	if (!is_solvable(g))
	{
		write(2, "Error: Map cannot be solved\n", 29);
		exit_game(g);
	}
}

void	parse_template(t_game *g, char *filepath)
{
	size_t	len;
	char	*ext;

	len = ft_strlen(filepath);
	ext = &filepath[len - 4];
	if (ft_strncmp(".ber", ext, 4))
	{
		write(2, "Error! map template must be a .ber file\n", 41);
		exit_game(g);
	}
	g->map_h = count_lines(filepath);
	if (g->map_h < 0)
	{
		perror("Error (Open file)");
		exit_game(g);
	}
	load_map(g, filepath);
	g->map_w = ft_strlen(g->map[0]);
	if (g->map_h > 15 || g->map_w > 28)
	{
		write(2, "Error! Map will not fit screen\n", 32);
		exit_game(g);
	}
	validate_map(g);
}
