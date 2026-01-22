/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:33:50 by mpedraza          #+#    #+#             */
/*   Updated: 2026/01/22 21:45:11 by mpedraza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd((nb % 10 + 48), fd);
	}
	if (nb < 10)
		ft_putchar_fd((nb + 48), fd);
}

void	print_instructions(void)
{
	write(1, "Prepare the onigiri!\n", 21);
	write(1, "- Pick up all the ingredients\n", 31);
	write(1, "- When ready, put it in the bento box!\n", 40);
	write(1, "--------------------------------------\n\n", 41);
}

void	print_status(t_game *g)
{
	write(1, "\r\033[KOnigiri Moves: ", 20);
	ft_putnbr_fd(g->p.moves, 1);
	if (g->p.status == BENTO)
	{
		write(1, "\nSUCCESS! YOUR ONIGIRI IS READY TO GO!", 39);
		write(1, "\nSo long and thanks for all the fish!", 38);
	}
}
