/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 16:48:33 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/28 22:04:53 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		check_if_player_won(t_grid grid)
{
	if (non_remplie(&grid) == 0)
	{
		ft_putendl("Grille pleine");
		return (1);
	}
	if (check_ligne(grid, 1) == 1)
	{
		ft_putendl("player win");
		return (1);
	}
	if (check_col(grid, 1) == 1)
	{
		ft_putendl("player win");
		return (1);
	}
	if (check_diag(grid, 1) == 1)
	{
		ft_putendl("player win");
		return (1);
	}
	else
		return (0);
}

int		check_if_ia_won(t_grid grid)
{
	if (non_remplie(&grid) == 0)
	{
		ft_putendl("Grille pleine");
		return (1);
	}
	if (check_ligne(grid, 2) == 1)
	{
		ft_putendl("IA win");
		return (1);
	}
	if (check_col(grid, 2) == 1)
	{
		ft_putendl("IA win");
		return (1);
	}
	if (check_diag(grid, 2) == 1)
	{
		ft_putendl("IA win");
		return (1);
	}
	else
		return (0);
}

int		check_ligne(t_grid grid, int nb)
{
	int		i;
	int		j;
	int		count;
	int		tmpj;

	i = 0;
	while (i < grid.nb_line)
	{
		j = 0;
		while (j < grid.nb_col)
		{
			tmpj = j;
			count = 0;
			while (tmpj < grid.nb_col && grid.tab[i][tmpj] == nb)
			{
				count++;
				tmpj++;
			}
			if (count == 4)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_col(t_grid grid, int nb)
{
	int		i;
	int		j;
	int		count;
	int		tmpi;

	j = 0;
	while (j < grid.nb_col)
	{
		i = 0;
		while (i < grid.nb_line)
		{
			tmpi = i;
			count = 0;
			while (tmpi < grid.nb_line && grid.tab[tmpi][j] == nb)
			{
				count++;
				tmpi++;
			}
			if (count == 4)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
