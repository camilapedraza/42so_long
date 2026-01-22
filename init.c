/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:43:13 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/22 21:31:49 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_objects(t_game *g)
{
	g->p.total = 0;
	g->p.x = 0;
	g->p.y = 0;
	g->p.items = 0;
	g->p.a = 0;
	g->p.c = 0;
	g->p.moves = 0;
	g->i.total = 0;
	g->i.a = 0;
	g->i.c = 0;
	g->e.total = 0;
	g->e.x = 0;
	g->e.y = 0;
	g->e.status = CLOSED;
}

static void	init_mlx_objects(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
}

static void	init_map_objects(t_game *g)
{
	g->map = NULL;
	g->map_w = 0;
	g->map_h = 0;
	g->test_map = NULL;
}

void	init_texture_objects(t_game *g)
{
	g->tx.w = NULL;
	g->tx.f = NULL;
	g->tx.p = NULL;
	g->tx.pa = NULL;
	g->tx.pc = NULL;
	g->tx.pca = NULL;
	g->tx.pcab = NULL;
	g->tx.e = NULL;
	g->tx.eo = NULL;
	g->tx.c = NULL;
	g->tx.a = NULL;
}

void	init_game_state(t_game *g)
{
	init_mlx_objects(g);
	init_map_objects(g);
	init_game_objects(g);
	init_texture_objects(g);
}
