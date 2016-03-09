/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:58:43 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/28 20:45:04 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		nb_valide(t_grid *grid)
{
	char	*line;
	int		nb;

	get_next_line(0, &line);
	nb = atoi(line);
	while (nb == 0 || nb > grid->nb_col)
	{
		ft_putstr("entree mauvaise essaie encore : ");
		ft_strdel(&line);
		get_next_line(0, &line);
		nb = atoi(line);
	}
	return (nb - 1);
}

int		check_full(t_grid *grid, int nb)
{
	int		i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i < grid->nb_line)
	{
		if (grid->tab[i][nb] == 0)
			return (1);
		i++;
	}
	return (0);
}

void	put_player_token(t_grid *grid, int nb)
{
	int		i;

	i = grid->nb_line - 1;
	while (grid->tab[i][nb] != 0)
		i--;
	grid->tab[i][nb] = 1;
	grid->i = i;
	grid->j = nb;
}

t_grid	*player_turn(t_grid *grid)
{
	int		nb;

	nb = nb_valide(grid);
	while (check_full(grid, nb) == 0)
	{
		ft_putstr("colone pleine essaie encore : ");
		nb = nb_valide(grid);
	}
	put_player_token(grid, nb);
	return (grid);
}
