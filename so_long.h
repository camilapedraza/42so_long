/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:01:43 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/14 19:26:24 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

#define TILE 32
#define MAP_W 8
#define MAP_H 8

typedef struct s_txtrs
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*item;
	int		h;
	int		w;
}	t_txtrs;

typedef struct s_game
{
	void	*mlx;
	void	*win;

	char	**map;
	int		map_w;
	int		map_h;

	int		player_x;
	int		player_y;
	int		items;
	int		moves;
}	t_game;

#endif
