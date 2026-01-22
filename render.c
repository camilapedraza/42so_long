/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:41:30 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/22 21:45:35 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_exit(t_game *g, int x, int y)
{
	if (g->e.status == CLOSED)
		mlx_put_image_to_window(g->mlx, g->win, g->tx.e, x * TILE, y * TILE);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->tx.eo, x * TILE, y * TILE);
}

void	render_player(t_game *g, int x, int y)
{
	if (g->p.status == BASE)
		mlx_put_image_to_window(g->mlx, g->win, g->tx.p, x * TILE, y * TILE);
	else if (g->p.status == NORI)
		mlx_put_image_to_window(g->mlx, g->win, g->tx.pa, x * TILE, y * TILE);
	else if (g->p.status == SAKE)
		mlx_put_image_to_window(g->mlx, g->win, g->tx.pc, x * TILE, y * TILE);
	else if (g->p.status == READY)
		mlx_put_image_to_window(g->mlx, g->win, g->tx.pca, x * TILE, y * TILE);
	else if (g->p.status == BENTO)
		mlx_put_image_to_window(g->mlx, g->win, g->tx.pcab, x * TILE, y * TILE);
}

void	render_tile(t_game *g, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->tx.w, x * TILE, y * TILE);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->tx.f, x * TILE, y * TILE);
	if (tile == 'P')
		render_player(g, x, y);
	if (tile == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->tx.c, x * TILE, y * TILE);
	if (tile == 'A')
		mlx_put_image_to_window(g->mlx, g->win, g->tx.a, x * TILE, y * TILE);
	if (tile == 'E')
		render_exit(g, x, y);
}

void	render_map(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			render_tile(g, g->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
