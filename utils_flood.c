/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flood.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:52:22 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/21 18:55:59 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_valid_path(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	flood_fill(char **test_map, int x, int y)
{
	if (test_map[y][x] == '1' || test_map[y][x] == 'X')
		return ;
	test_map[y][x] = 'X';
	
	flood_fill(test_map, x + 1, y);
	flood_fill(test_map, x - 1, y);
	flood_fill(test_map, x, y + 1);
	flood_fill(test_map, x, y - 1);
}