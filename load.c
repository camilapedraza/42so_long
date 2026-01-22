/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:49:05 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/22 19:08:39 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player_state(t_game *g)
{
	if (g->i.a == 0)
		g->p.status = NORI;
	else
		g->p.status = BASE;
}

void	load_mlx_window(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
	{
		write(2, "Failed to init MLX\n", 20);
		exit_game(g);
	}
	// TODO should I get display size with mlx_get_screen_size??
	g->win = mlx_new_window(g->mlx, 64 * g->map_w, 64 * g->map_h, "So Long");
	if (!g->win)
	{
		write(2, "Failed to create MLX window\n", 29);
		exit_game(g);
	}
}

void	load_assets(t_game *g)
{
	g->tx.w = mlx_xpm_file_to_image(g->mlx, "img/w.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.f = mlx_xpm_file_to_image(g->mlx, "img/f.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.p = mlx_xpm_file_to_image(g->mlx, "img/p.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.pa = mlx_xpm_file_to_image(g->mlx, "img/pa.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.pc = mlx_xpm_file_to_image(g->mlx, "img/pc.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.pca = mlx_xpm_file_to_image(g->mlx, "img/pca.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.pcab = mlx_xpm_file_to_image(g->mlx, "img/pcab.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.e = mlx_xpm_file_to_image(g->mlx, "img/e.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.eo = mlx_xpm_file_to_image(g->mlx, "img/eo.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.c = mlx_xpm_file_to_image(g->mlx, "img/c.xpm", &g->tx.t_w, &g->tx.t_h);
	g->tx.a = mlx_xpm_file_to_image(g->mlx, "img/a.xpm", &g->tx.t_w, &g->tx.t_h);

	if (!g->tx.w || !g->tx.f || !g->tx.p || !g->tx.pa || !g->tx.pca || !g->tx.pcab || !g->tx.e || !g->tx.eo || !g->tx.c || !g->tx.a)
	{
		write(2, "Error! Failed to load XPM files\n", 33);
		exit_game(g);
	}
}
