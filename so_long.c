/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:21:49 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/17 20:21:37 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	exit_game(t_game *g)
{
	// TODO CLEAN UP MLX stuff
	// TODO IMPLEMENT ERROR CODES?
	(void)g;
	exit(0);
}

void	init_game(t_game *g)
{	
	load_mlx_window(g);
	load_assets(g);
	init_map(g);
	mlx_key_hook(g->win, handle_keypress, g);
}

int count_lines(char *filepath)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (-1);
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

void	populate_map(t_game *g, char *filepath)
{
	int		fd;
	int		y;
	char	*line;
	int		len;
	
	fd = open(filepath, O_RDONLY);
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
		exit_game(g); // free allocated lines!
	g->map[y] = NULL;
	close(fd);
}

int 	is_rectangle(t_game *g)
{
	int	y;
	if (!g->map)
		return (0);
	y = 0;
	while (g->map[y])
	{
		if(ft_strlen(g->map[y]) != (size_t)g->map_w)
			return (0);
		y++;
	}
	return (1);
}
int		has_valid_objects(t_game *g)
{
	int		y;
	int		x;
	//t_objs	count;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[x])
		{
			if (!ft_strchr(MAP_MARKERS, g->map[y][x]))
				return (0);
		}
		// check P, E and C (exist and in right number)
	}
	return (1);
}
int		has_valid_border(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[x])
		{
			if (x == 0 || x == g->map_h)
			{
				if (g->map[y][x] != '1')
					return (0);
			}
			else if (y == 0 || y == g->map_w)
			{
				if (g->map[y][x] != '1')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

void	validate_map(t_game *g)
{

	// map should be AT LEAST 3 lines for it to be valid
	if (g->map_h < 3)
	{
		write(1, "Map too small\n", 15);
		exit_game(g);
	}
		// all lines should be the same len for it to be valid
	if (!is_rectangle(g))
	{
		write(1, "Map not a rectangle\n", 15);
		exit_game(g);
	}
	if (!has_valid_objects(g))
	{

	}
	if (!has_valid_border(g))
	{
		write(1, "Map is has invalid wall border\n", 15);
		exit_game(g);
	}


	
	// No characters outside of 10PCEA
}

void	parse_template(t_game *g, char *filepath)
{
	g->map_h = count_lines(filepath);
	if (g->map_h < 0)
	{
		write(1, "Error loading map file\n", 24);
		exit_game(g);
	}
	// should we check for a max number of lines?
	populate_map(g, filepath);
	g->map_w = ft_strlen(g->map[0]);
	//validate_map(g);
}

int	main(int ac, char **av)
{
	t_game g;

	if (ac != 2)
		exit(EXIT_FAILURE);
	parse_template(&g, av[1]);
	// add usage message?
	// TODO validate args
	// TODO validate map
	// TODO determine map with and height so new_window can use it
	init_game(&g);
	// how to update player look based on picked up collectibles
	mlx_loop(g.mlx);
	// anything after this will never run
}
