/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:32:17 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/22 19:37:55 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_game_state(t_game *g)
{
	if (g->p.c == g->i.c && g->p.a == g->i.a)
		g->e.status = OPEN;
	else
		g->e.status = CLOSED;
	if (g->p.c == 0 && g->p.a == 0)
		g->p.status = BASE;
	if (g->p.c == g->i.c && g->p.a == g->i.a)
		g->p.status = READY;
	else if (g->p.c == g->i.c && g->p.a != g->i.a)
		g->p.status = SAKE;
	else if (g->p.c != g->i.c && g->p.a == g->i.a)
		g->p.status = NORI;
}

static void	execute_move(t_game *g, int d_x, int d_y)
{
	g->map[g->p.y][g->p.x] = '0';
	g->p.x = d_x;
	g->p.y = d_y;
	g->map[d_y][d_x] = 'P';
	g->p.moves += 1;
	print_status(g);
}

static void parse_move(t_game *g, int move_x, int move_y)
{
	int d_x;
	int d_y;

	d_x = g->p.x + move_x;
	d_y = g->p.y + move_y;

	if (g->map[d_y][d_x] == '1' || g->p.status == BENTO)
		return;
	if (g->map[d_y][d_x] == 'E')
	{
		if (g->e.status == CLOSED)
			return;
		if (g->e.status == OPEN)
			g->p.status = BENTO;
	}
	if (g->map[d_y][d_x] == 'C' || g->map[d_y][d_x] == 'A')
	{
		if (g->map[d_y][d_x] == 'C')
			g->p.c++;
		else
			g->p.a++;
		update_game_state(g);
	}
	execute_move(g, d_x, d_y);
	render_map(g);
}

int handle_keypress(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		exit_game(g);
	else if (keycode == KEY_UP)
		parse_move(g, 0, -1);
	else if (keycode == KEY_DOWN)
		parse_move(g, 0, 1);
	else if (keycode == KEY_LEFT)
		parse_move(g, -1, 0);
	else if (keycode == KEY_RIGHT)
		parse_move(g, 1, 0);
	return (0);
}