/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:01:43 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/15 16:33:34 by mpedraza         ###   ########.fr       */
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

	t_plyr	p;
	t_txtr	tx;
}	t_game;

#endif
