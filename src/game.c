/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:27:00 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/28 22:26:19 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	print_grid(t_grid *grid)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	tmp = grid->nb_col;
	while (i < grid->nb_col)
	{
		ft_putstr("\x1b[33m");
		ft_putnbr(i + 1);
		ft_putstr("\x1b[0m");
		ft_putstr(" | ");
		i++;
	}
	ft_putchar('\n');
	ft_putchar('\n');
	print_tab(grid->tab, grid->nb_col, grid->nb_line);
}

int		non_remplie(t_grid *grid)
{
	int		i;
	int		j;

	i = 0;
	while (i < grid->nb_line)
	{
		j = 0;
		while (j < grid->nb_col)
		{
			if (grid->tab[i][j] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	player_first(t_grid *grid)
{
	int res;
	int	i;

	i = 1;
	res = 0;
	while (i <= 21)
	{
		ft_putendl("PLAYER TURN");
		print_grid(grid);
		ft_putchar('\n');
		grid = player_turn(grid);
		res = check_if_player_won(*grid);
		if (res == 1)
			break ;
		ft_putendl("IA TURN");
		print_grid(grid);
		ft_putchar('\n');
		grid = ia_turn(grid);
		res = check_if_ia_won(*grid);
		if (res == 1)
			break ;
		i++;
	}
}

void	ia_first(t_grid *grid)
{
	int		res;
	int		i;

	i = 1;
	res = 0;
	grid->i = 0;
	grid->j = 0;
	while (i <= 21)
	{
		ft_putendl("IA TURN");
		grid = ia_turn(grid);
		res = check_if_ia_won(*grid);
		print_grid(grid);
		ft_putchar('\n');
		if (res == 1)
			break ;
		ft_putendl("PLAYER TURN");
		grid = player_turn(grid);
		res = check_if_player_won(*grid);
		print_grid(grid);
		ft_putchar('\n');
		if (res == 1)
			break ;
		i++;
	}
}

void	play_the_game(t_grid *grid)
{
	int		i;

	srand((unsigned int)time(NULL));
	i = rand() % 2;
	if (i == 0)
		player_first(grid);
	else
		ia_first(grid);
}
