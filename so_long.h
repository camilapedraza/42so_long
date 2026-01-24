/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:01:43 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/24 18:22:43 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdio.h>

# define TILE 64
# define BUFFER_SIZE 100

# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364
# define KEY_A		97
# define KEY_W		119
# define KEY_D		100
# define KEY_S		115

# define MAP_MARKERS "01PCEA"

enum	e_exit
{
	CLOSED,
	OPEN,
};

enum e_plyr
{
	BASE,
	NORI,
	SAKE,
	READY,
	BENTO
};

typedef struct s_player
{
	int			total;
	int			x;
	int			y;
	int			items;
	int			a;
	int			c;
	int			moves;
	enum e_plyr	status;
}	t_plyr;

typedef struct s_items
{
	int	c;
	int	a;
}	t_itms;

typedef struct s_exit
{
	int			total;
	int			x;
	int			y;
	enum e_exit	status;
}	t_exit;

typedef struct s_textures
{
	void	*w;
	void	*f;
	void	*p;
	void	*pa;
	void	*pc;
	void	*pca;
	void	*pcab;
	void	*e;
	void	*eo;
	void	*c;
	void	*a;
	int		t_h;
	int		t_w;
}	t_txtr;

typedef struct s_game
{
	void	*mlx;
	void	*win;

	char	**map;
	int		map_w;
	int		map_h;

	char	**test_map;

	t_plyr	p;
	t_itms	i;
	t_exit	e;
	t_txtr	tx;
}	t_game;

/*  LOADING LIBS AND ASSETS  */
void	load_mlx_window(t_game *g);
void	load_assets(t_game *g);
void	load_player_state(t_game *g);

/*  PARSING & VALIDATING MAP  */
void	load_map(t_game *g, char *filepath);
void	validate_map(t_game *g);
void	parse_template(t_game *g, char *filepath);
int		is_rectangle(t_game *g);
int		has_valid_objects(t_game *g);
int		has_valid_border(t_game *g);
int		is_solvable(t_game *g);

/*  INITIALIZING GRAPHICS AND OBJECTS */
void	init_game_state(t_game *g);

/*  RENDERING GRAPHICS  */
void	render_tile(t_game *g, char tile, int x, int y);
void	render_map(t_game *g);

/*	PRINTING MESSAGES  */
void	print_instructions(void);
void	print_status(t_game *g);

/*  HANDLING INPUT  */
int		handle_keypress(int keycode, t_game *g);

/*	FREE, CLOSE, EXIT  */
int		exit_game(t_game *g, int error);

/* 	HELPERS  */
char	*get_next_line(int fd);

/*  UTILITIES: STRINGS  */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

/*  UTILITIES: FLOOD FILL  */
int		has_valid_item_path(char **map);
int		has_valid_exit_path(char **map);
void	flood_fill_items(char **test_map, int x, int y);
void	flood_fill_exit(char **test_map, int x, int y);

#endif
