/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:21:49 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/24 18:16:35 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *g)
{	
	load_mlx_window(g);
	load_assets(g);
	load_player_state(g);
	render_map(g);
	print_instructions();
	mlx_key_hook(g->win, handle_keypress, g);
	mlx_hook(g->win, 17, 0, exit_game, g);
}

int	main(int ac, char **av)
{
	t_game	g;

	if (ac != 2)
	{
		write(2, "Error! Please provide a map:\n", 30);
		write(2, "./so_long map.ber\n", 19);
		exit(EXIT_FAILURE);
	}
	init_game_state(&g);
	parse_template(&g, av[1]);
	init_game(&g);
	mlx_loop(g.mlx);
}
