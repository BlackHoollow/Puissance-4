/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 18:59:58 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/28 22:17:04 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		col_fill(t_grid *grid, int nb)
{
	int		i;
	int		j;
	int		count;

	j = 0;
	while (j < grid->nb_col)
	{
		i = 0;
		while (i < grid->nb_line)
		{
			count = col_fill_2(grid, nb, i, j);
			if (count == 3)
			{
				if (double_check(grid, j) == 1)
					return (j);
			}
			else
				count = 0;
			i++;
		}
		j++;
	}
	return (0);
}

void	put_ia_token(t_grid *grid, int nb)
{
	int		i;

	i = grid->nb_line - 1;
	while (grid->tab[i][nb] != 0)
		i--;
	grid->tab[i][nb] = 2;
}

int		double_check(t_grid *grid, int nb)
{
	int		i;

	i = grid->nb_line - 1;
	while (grid->tab[i][nb] != 1)
		i--;
	if (grid->tab[i - 3][nb] == 0)
		return (1);
	return (0);
}

int		check_side(t_grid *grid, int i, int j)
{
	if (j == 0 || j == grid->nb_col - 1)
		return (0);
	if (grid->tab[i][j - 1] == 0)
		return (1);
	if (grid->tab[i][j + 1] == 0)
		return (2);
	if (check_full(grid, j) == 1)
		return (3);
	return (0);
}

t_grid	*ia_turn(t_grid *grid)
{
	int		fill;
	int		j;
	int		res;

	j = 0;
	fill = col_fill(grid, 1);
	if (fill != 0)
	{
		put_ia_token(grid, fill);
		return (grid);
	}
	res = check_side(grid, grid->i, grid->j);
	if (res == 1)
		put_ia_token(grid, grid->j - 1);
	else if (res == 2)
		put_ia_token(grid, grid->j + 1);
	else if (res == 3)
		put_ia_token(grid, grid->j);
	else
	{
		while (check_full(grid, j) == 0)
			j++;
		put_ia_token(grid, j);
	}
	return (grid);
}
