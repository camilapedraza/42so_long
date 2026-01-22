/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:21:49 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/22 16:12:05 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	exit_game(t_game *g)
{
	// TODO CLEAN UP MLX stuff
	// TODO IMPLEMENT ERROR CODES?
	(void)g;
	exit(0);
}

void	init_game(t_game *g)
{	
	load_mlx_window(g);
	load_assets(g);
	render_map(g);
	mlx_key_hook(g->win, handle_keypress, g);
}

int	main(int ac, char **av)
{
	t_game g;

	if (ac != 2)
		exit(EXIT_FAILURE);
	init_game_state(&g);
	// TODO initialize the game struct so no values will cause read segfaults?
	parse_template(&g, av[1]);
	// add usage message?
	// TODO validate args
	// TODO validate map
	// TODO determine map with and height so new_window can use it
	init_game(&g);
	// how to update player look based on picked up collectibles
	mlx_loop(g.mlx);
}
// TODO: Check all places with error messages - implement perror where needed