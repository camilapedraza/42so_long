/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:01:43 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/21 16:18:09 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>

# define TILE 64
# define BUFFER_SIZE 100

# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

# define MAP_MARKERS "01PCEA"

enum	e_exit
{
	CLOSED,
	OPEN,
	REACHED
};

typedef struct s_obj_count
{
	int	p;
	int	c;
	int	e;
}	t_objs;

typedef struct s_player
{
	int	x;
	int	y;
	int	items;
	int	a;
	int	c;
	int	moves;
}	t_plyr;

typedef struct s_items
{
	int total;
	int c;
	int a;
} t_itms;

typedef struct s_exit
{
	int			x;
	int			y;
	enum e_exit status;
} t_exit;

typedef struct s_textures
{
	void *w;
	void *f;
	void *p;
	void *e;
	void *c;
	void *a;
	int t_h;
	int t_w;
} t_txtr;

typedef struct s_game
{
	void	*mlx;
	void	*win;

	char	**map;
	int		map_w;
	int		map_h;
	
	t_objs	o;
	t_plyr	p;
	t_itms	i;
	t_exit	e;
	t_txtr	tx;
}	t_game;

/*  LOADING LIBS AND ASSETS  */
void	load_mlx_window(t_game *g);
void	load_assets(t_game *g);
void	exit_game(t_game *g);

/*  INITIALIZING GRAPHICS AND OBJECTS */
void	init_player(t_game *g, int x, int y);
void	init_tile(t_game *g, char tile, int x, int y);
void	init_map(t_game *g);

/*  RENDERING GRAPHICS  */
void	render_tile(t_game *g, char tile, int x, int y);
void	render_map(t_game *g);

/*  HANDLING INPUT  */
void	move(t_game *g, int move_x, int move_y);
int		handle_keypress(int keycode, t_game *g);

/* 	HELPERS  */
char	*get_next_line(int fd);

/*  UTILITIES  */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
