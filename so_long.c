/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:21:49 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/14 19:45:15 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	(void)av;
	(void)ac;
	
	//if (ac != 2)
		//exit(EXIT_FAILURE);
	// check parameter is a .ber file and open it

	void	*mlx;
	void	*mlx_win;
	t_txtrs	tx;

	mlx = mlx_init();
	if (!mlx)
	{
		write(2, "Failed to init MLX\n", 20);
		exit(EXIT_FAILURE);
	}
	// create window
	mlx_win = mlx_new_window(mlx, 600, 600, "So Long Test");
	if (!mlx_win)
	{
		write(2, "Failed to create MLX window\n", 29);
		exit(EXIT_FAILURE);
	}

	// load xpm assets
	tx.player = mlx_xpm_file_to_image(mlx, "asset_onigiri.xpm", &tx.w, &tx.h);
	tx.floor = mlx_xpm_file_to_image(mlx, "asset_floor.xpm", &tx.w, &tx.h);
	tx.wall = mlx_xpm_file_to_image(mlx, "asset_wall.xpm", &tx.w, &tx.h);
	tx.item = mlx_xpm_file_to_image(mlx, "asset_salmon.xpm", &tx.w, &tx.h);

	if (!tx.player || !tx.floor || !tx.wall || !tx.item)
	{
		write(2, "Failed to load XPM\n", 20);
		exit(EXIT_FAILURE);
	}

	char *map[MAP_H] = {
		"11111111",
		"10000001",
		"10000001",
		"10P000C1",
		"10000001",
		"10000001",
		"10000001",
		"11111111"};

	int y = 0;
	int x;
	while (y < MAP_H)
	{
		x = 0;
		while (x < MAP_W)
		{
			char tile = map[y][x];
			if (tile == '1')
				mlx_put_image_to_window(mlx, mlx_win, tx.wall, x * TILE, y * TILE);
			else
				mlx_put_image_to_window(mlx, mlx_win, tx.floor, x * TILE, y * TILE);

			if (tile == 'P')
				mlx_put_image_to_window(mlx, mlx_win, tx.player, x * TILE, y * TILE);
			if (tile == 'C')
				mlx_put_image_to_window(mlx, mlx_win, tx.item, x * TILE, y * TILE);
			x++;
		}
		y++;
	}
	//draw_floor();
	//draw_walls();
	//draw_exit();
	//draw_collectibles();
	//draw_player();
	// set hooks here
	mlx_loop(mlx);
	// anything after this will never run
	
}