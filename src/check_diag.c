/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_diag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 20:06:14 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/28 21:57:22 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		check_diag(t_grid grid, int nb)
{
	if (check_diag_right(grid, nb) == 1)
		return (1);
	else if (check_diag_left(grid, nb) == 1)
		return (1);
	else
		return (0);
}

int		check_diag_right(t_grid grid, int nb)
{
	int		i;
	int		j;

	i = 3;
	while (i < grid.nb_line)
	{
		j = 0;
		while (j < (grid.nb_col - 3))
		{
			if (check_diag_right_2(grid, nb, i, j == 1))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_diag_left(t_grid grid, int nb)
{
	int		i;
	int		j;

	i = 3;
	while (i < grid.nb_line)
	{
		j = 3;
		while (j < grid.nb_col)
		{
			if (check_diag_left_2(grid, nb, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
