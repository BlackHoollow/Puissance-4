/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 21:46:17 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/28 22:07:14 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		check_diag_right_2(t_grid grid, int nb, int i, int j)
{
	int		tmpi;
	int		tmpj;
	int		count;

	tmpj = j;
	tmpi = i;
	count = 0;
	while (tmpi >= 0 && grid.tab[tmpi][tmpj] == nb)
	{
		if (tmpi != 0)
			tmpi--;
		tmpj++;
		count++;
	}
	if (count == 4)
		return (1);
	else
		return (0);
}

int		check_diag_left_2(t_grid grid, int nb, int i, int j)
{
	int		count;
	int		tmpi;
	int		tmpj;

	tmpi = i;
	tmpj = j;
	count = 0;
	while (tmpi >= 0 && grid.tab[tmpi][tmpj] == nb)
	{
		if (tmpi != 0)
			tmpi--;
		tmpj--;
		count++;
	}
	if (count == 4)
		return (1);
	else
		return (0);
}

int		col_fill_2(t_grid *grid, int nb, int i, int j)
{
	int		tmpi;
	int		count;

	tmpi = i;
	count = 0;
	while (tmpi < grid->nb_line && grid->tab[tmpi][j] == nb)
	{
		count++;
		tmpi++;
	}
	return (count);
}
