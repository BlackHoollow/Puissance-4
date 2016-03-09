/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:43:01 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/28 21:48:28 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	print_tab(int **tab, int nb_col, int nb_line)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (j < nb_col)
		{
			print_token(tab[i][j]);
			if (j < 8)
				ft_putstr(" | ");
			else
				ft_putstr(" |  ");
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	fill_it(int *tab, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		tab[i] = 0;
		i++;
	}
}

int		assign_grid(char **argv, t_grid *grid)
{
	int		nb_line;
	int		nb_col;
	int		i;

	i = 0;
	nb_line = atoi(argv[1]);
	if (nb_line < 6)
		return (0);
	nb_col = atoi(argv[2]);
	if (nb_col < 7)
		return (0);
	grid->nb_line = nb_line;
	grid->nb_col = nb_col;
	grid->tab = (int **)malloc(sizeof(int *) * nb_line);
	while (i < nb_line)
	{
		grid->tab[i] = (int *)malloc(sizeof(int) * nb_col);
		fill_it(grid->tab[i], nb_col);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_grid	grid;

	if (argc != 3)
		return (0);
	if (assign_grid(argv, &grid) == 0)
	{
		ft_putendl("False arguments");
		return (0);
	}
	play_the_game(&grid);
	return (0);
}
