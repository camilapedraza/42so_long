/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:21:49 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/15 20:32:40 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	move(t_game *g, int move_x, int move_y)
{
	int	dest_x;
	int dest_y;

	dest_x = g->p.x + move_x;
	dest_y = g->p.y + move_y;

	if (g->map[dest_y][dest_x] == 1)
		return ;
	// TODO add logic if == E but P has not picked up all C
	// TODO add logic if == C 
	g->map[g->p.y][g->p.x] = '0';
	g->p.x = dest_x;
	g->p.y = dest_y;
	g->map[dest_y][dest_x] = 'P';
	g->p.moves++;
	render_map(g);
}


void	init_game(t_game *g)
{
	char *map[8] = {
		"11111111",
		"10000001",
		"10001111",
		"10P010C1",
		"10001001",
		"10000001",
		"100A0001",
		"11111111"};

	g->map = map;
	load_mlx_window(g);
	load_assets(g);
	init_map(g);
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
	// TODO determine map with and height so new_window can use it
	init_game(&g);
	//mlx_key_hook(g.win, );
	// set hooks here
	// how to update player look based on picked up collectibles
	mlx_loop(g.mlx);
	// anything after this will never run
	
}
