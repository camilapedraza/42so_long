/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:21:49 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/15 16:42:55 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *g, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->tx.w, x * TILE, y * TILE);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->tx.f, x * TILE, y * TILE);
	if (tile == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->tx.p, x * TILE, y * TILE);
	if (tile == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->tx.c, x * TILE, y * TILE);
}

void	render_map(t_game *g)
{
	int y;
	int x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			render_tile(g, g->map[y][x], x, y);
			;
			x++;
		}
		y++;
	}
}

void	load_mlx_window(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
	{
		write(2, "Failed to init MLX\n", 20);
		exit(EXIT_FAILURE);
	}
	g->win = mlx_new_window(g->mlx, 64 * 8, 64 * 8, "So Long");
	if (!g->win)
	{
		write(2, "Failed to create MLX window\n", 29);
		// TODO destroy MLX and point to NULL before exiting
		exit(EXIT_FAILURE);
	}
}

void	load_assets(t_game *g)
{
	/*
	g->tx.p = mlx_xpm_file_to_image(g->mlx, "img/p0.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.f = mlx_xpm_file_to_image(g->mlx, "img/f.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.w = mlx_xpm_file_to_image(g->mlx, "img/w.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.c = mlx_xpm_file_to_image(g->mlx, "img/c1.xpm", &g->tx.t_w, &g->tx.t_h);
	*/

	g->tx.p = mlx_xpm_file_to_image(g->mlx, "img/p0.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.f = mlx_xpm_file_to_image(g->mlx, "img/f.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.w = mlx_xpm_file_to_image(g->mlx, "img/w.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.c = mlx_xpm_file_to_image(g->mlx, "img/c1.xpm", &g->tx.t_w, &g->tx.t_h);

	if (!g->tx.p || !g->tx.f || !g->tx.w || !g->tx.c)
	{
		write(2, "Failed to load XPM\n", 20);
		// TODO destroy assets, window, MLX, and point to NULL before exiting
		exit(EXIT_FAILURE);
	}
}

void	init_game(t_game *g)
{
	char *map[8] = {
		"11111111",
		"10000001",
		"10000001",
		"10P000C1",
		"10000001",
		"10000001",
		"10000001",
		"11111111"};

	g->map = map;
	load_mlx_window(g);
	load_assets(g);
	render_map(g);
}


int	main(int ac, char **av)
{
	(void)av;
	(void)ac;
	
	//if (ac != 2)
		//exit(EXIT_FAILURE);
	// check parameter is a .ber file and open it

	t_game	g;
	
	// TODO validate args
	// TODO validate map
	init_game(&g);




	//draw_floor();
	//draw_walls();
	//draw_exit();
	//draw_collectibles();
	//draw_player();
	// set hooks here
	mlx_loop(g.mlx);
	// anything after this will never run
	
}
