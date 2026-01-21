/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:55:23 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/21 18:56:11 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_rectangle(t_game *g)
{
	int y;
	if (!g->map)
		return (0);
	y = 0;
	while (g->map[y])
	{
		if (ft_strlen(g->map[y]) != (size_t)g->map_w)
			return (0);
		y++;
	}
	return (1);
}

static void set_objets(char obj, t_game *g, int x, int y)
{
	if (obj == 'C')
		g->o.c++;
	if (obj == 'E')
		g->o.e++;
	if (obj == 'P')
	{
		g->o.p++;
		g->p.x = x;
		g->p.y = y;
	}
}

int has_valid_objects(t_game *g)
{
	int y;
	int x;

	g->o.p = 0;
	g->o.c = 0;
	g->o.e = 0;
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (!ft_strchr(MAP_MARKERS, g->map[y][x]))
				return (0);
			set_objets(g->map[y][x], g, x, y);
			x++;
		}
		y++;
	}
	if (g->o.p != 1 || g->o.e != 1 || g->o.c < 1)
		return (0);
	return (1);
}

int has_valid_border(t_game *g)
{
	int y;
	int x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (y == 0 || y == g->map_h)
			{
				if (g->map[y][x] != '1')
					return (0);
			}
			if (x == 0 || x == g->map_w - 1)
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

int	is_solvable(t_game *g)
{
	int		y;

	g->test_map = malloc(sizeof(char *) * (g->map_h + 1));
	if (!g->test_map)
		return (0);
	y = 0;
	while (g->map[y])
	{
		g->test_map[y] = ft_strdup(g->map[y]);
		if (!g->test_map[y])
			return (0);
		y++;
	}
	g->test_map[y] = NULL;
	flood_fill(g->test_map, g->p.x, g->p.y);
	if (!has_valid_path(g->test_map))
		return (0);
	return (1);
}
