/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:01:43 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/15 19:59:07 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

#define TILE 64

typedef struct s_textures
{
	void	*w;
	void	*f;
	void	*p;
	void	*e;
	void	*c;
	void	*a;
	int		t_h;
	int		t_w;
}	t_txtr;

typedef struct s_player
{
	int		x;
	int		y;
	int		items;
	int		moves;
}	t_plyr;


typedef struct s_game
{
	void	*mlx;
	void	*win;

	char	**map;
	int		map_w;
	int		map_h;
	int		items;

	t_plyr	p;
	t_txtr	tx;
}	t_game;

/*  LOADING LIBS AND ASSETS  */
void	load_mlx_window(t_game *g);
void	load_assets(t_game *g);

/*  INITIALIZING GRAPHICS AND OBJECTS */
void	init_player(t_game *g, int x, int y);
void	init_tile(t_game *g, char tile, int x, int y);
void	init_map(t_game *g);

	/*  RENDERING GRAPHICS  */
void	render_tile(t_game *g, char tile, int x, int y);
void	render_map(t_game *g);

#endif
