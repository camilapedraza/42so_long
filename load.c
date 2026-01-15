/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:49:05 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/15 20:37:35 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	g->tx.p = mlx_xpm_file_to_image(g->mlx, "img/pca.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.f = mlx_xpm_file_to_image(g->mlx, "img/f.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.w = mlx_xpm_file_to_image(g->mlx, "img/w.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.c = mlx_xpm_file_to_image(g->mlx, "img/c.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.a = mlx_xpm_file_to_image(g->mlx, "img/a.xpm", &g->tx.t_w, &g->tx.t_h);

	if (!g->tx.p || !g->tx.f || !g->tx.w || !g->tx.c || !g->tx.a)
	{
		write(2, "Failed to load XPM\n", 20);
		// TODO destroy malloced assets, window, MLX, and point to NULL before exiting
		exit(EXIT_FAILURE);
	}
}