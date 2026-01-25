/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:38:02 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/25 16:04:14 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map && *map)
	{
		while (map[i])
			free(map[i++]);
		free(map);
	}
}

static void	free_textures(t_game *g)
{
	if (g->tx.w)
		mlx_destroy_image(g->mlx, g->tx.w);
	if (g->tx.f)
		mlx_destroy_image(g->mlx, g->tx.f);
	if (g->tx.p)
		mlx_destroy_image(g->mlx, g->tx.p);
	if (g->tx.pa)
		mlx_destroy_image(g->mlx, g->tx.pa);
	if (g->tx.pc)
		mlx_destroy_image(g->mlx, g->tx.pc);
	if (g->tx.pca)
		mlx_destroy_image(g->mlx, g->tx.pca);
	if (g->tx.pcab)
		mlx_destroy_image(g->mlx, g->tx.pcab);
	if (g->tx.e)
		mlx_destroy_image(g->mlx, g->tx.e);
	if (g->tx.eo)
		mlx_destroy_image(g->mlx, g->tx.eo);
	if (g->tx.c)
		mlx_destroy_image(g->mlx, g->tx.c);
	if (g->tx.a)
		mlx_destroy_image(g->mlx, g->tx.a);
}

int	exit_game(t_game *g, int error)
{
	if (g->map)
		free_map(g->map);
	if (g->test_map)
		free_map(g->test_map);
	g->map = NULL;
	g->test_map = NULL;
	free_textures(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	#ifdef LINUX
		if (g->mlx)
			mlx_destroy_display(g->mlx);
	#endif
	if (g->mlx)
		free(g->mlx);
	g->mlx = NULL;
	g->win = NULL;
	if (error)
		exit(EXIT_FAILURE);
	write(2, "\nSo long, and thanks for all the fish! (｡･ω･)ﾉﾞ\n", 60);
	exit(EXIT_SUCCESS);
	return (0);
}
