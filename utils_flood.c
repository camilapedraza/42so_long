/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flood.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:52:22 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/22 21:47:03 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_valid_exit_path(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	has_valid_item_path(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'A')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	flood_fill_items(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '#' || map[y][x] == 'E')
		return ;
	map[y][x] = '#';
	flood_fill_items(map, x + 1, y);
	flood_fill_items(map, x - 1, y);
	flood_fill_items(map, x, y + 1);
	flood_fill_items(map, x, y - 1);
}

void	flood_fill_exit(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '$')
		return ;
	map[y][x] = '$';
	flood_fill_exit(map, x + 1, y);
	flood_fill_exit(map, x - 1, y);
	flood_fill_exit(map, x, y + 1);
	flood_fill_exit(map, x, y - 1);
}
