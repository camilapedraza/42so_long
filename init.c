/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:43:13 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/22 16:08:50 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_objects(t_game *g)
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
void	init_game_state(t_game *g)
{
	init_objects(g);
}