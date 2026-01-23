/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:21:49 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/23 16:48:47 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO fix handoff with exit_game
// TODO understand how it can return 0 if exit game exits before that
int	close_game(t_game *g)
{
	exit_game(g);
	return (0);
}

// TODO CLEAN UP MLX stuff
// TODO IMPLEMENT ERROR CODES?

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_textures(t_game *g)
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
void	exit_game(t_game *g)
{
	int	i;
	
	i = 0;
	if (g->map)
	{
		free_map(g->map);
		g->map = NULL;
	}
	if (g->test_map)
	{
		free_map(g->test_map);
		g->test_map = NULL;
	}
	free_textures(g);
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->win)
		mlx_destroy_display(g->mlx);
	if (g->mlx)
		free(g->mlx);
	g->mlx = NULL;
	g->win = NULL;
	exit(0);
}

void	init_game(t_game *g)
{	
	load_mlx_window(g);
	load_assets(g);
	load_player_state(g);
	render_map(g);
	print_instructions();
	mlx_key_hook(g->win, handle_keypress, g);
	mlx_hook(g->win, 17, 0, close_game, g);
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
// TODO: Check all places with error messages - implement perror where needed