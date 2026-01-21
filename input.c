/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:32:17 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/21 16:17:35 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move(t_game *g, int move_x, int move_y)
{
	int dest_x;
	int dest_y;

	dest_x = g->p.x + move_x;
	dest_y = g->p.y + move_y;

	if (g->map[dest_y][dest_x] == '1')
		return;
	// TODO add logic if == E but P has not picked up all C
	// TODO add logic if == C
	// TODO add logic if == A
	g->map[g->p.y][g->p.x] = '0';
	g->p.x = dest_x;
	g->p.y = dest_y;
	g->map[dest_y][dest_x] = 'P';
	g->p.moves += 1;
	render_map(g);
}

int handle_keypress(int keycode, t_game *g)
{
	if (keycode == KEY_ESC)
		exit_game(g);
	else if (keycode == KEY_UP)
		move(g, 0, -1);
	else if (keycode == KEY_DOWN)
		move(g, 0, 1);
	else if (keycode == KEY_LEFT)
		move(g, -1, 0);
	else if (keycode == KEY_RIGHT)
		move(g, 1, 0);
	return (0);
}