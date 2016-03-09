/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:43:35 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/28 22:09:03 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include "libft.h"

typedef struct	s_grid
{
	int		nb_line;
	int		nb_col;
	int		**tab;
	int		i;
	int		j;
}				t_grid;

/*
**	color.c
*/

void			print_token(int player);

/*
**	core.c
*/

void			print_tab(int **tab, int nb_col, int nb_line);
void			fill_it(int *tab, int nb);
int				assign_grid(char **argv, t_grid *grid);
int				main(int argc, char **argv);

/*
**	game.c
*/

void			print_grid(t_grid *grid);
int				non_remplie(t_grid *grid);
void			player_first(t_grid *grid);
void			ia_first(t_grid *grid);
void			play_the_game(t_grid *grid);

/*
**	player.c
*/

int				nb_valide(t_grid *grid);
int				check_full(t_grid *grid, int nb);
void			put_player_token(t_grid *grid, int nb);
t_grid			*player_turn(t_grid *grid);

/*
**	check_win.c
*/

int				check_if_player_won(t_grid grid);
int				check_if_ia_won(t_grid grid);
int				check_ligne(t_grid grid, int nb);
int				check_col(t_grid grid, int nb);

/*
**	check_diag.c
*/

int				check_diag(t_grid grid, int nb);
int				check_diag_right(t_grid grid, int nb);
int				check_diag_left(t_grid grid, int nb);

/*
**	ia.c
*/

int				col_fill(t_grid *grid, int nb);
void			put_ia_token(t_grid *grid, int nb);
int				double_check(t_grid *grid, int nb);
int				check_side(t_grid *grid, int i, int j);
t_grid			*ia_turn(t_grid *grid);

/*
**	norme.c
*/

int				check_diag_right_2(t_grid grid, int nb, int i, int j);
int				check_diag_left_2(t_grid grid, int nb, int i, int j);
int				col_fill_2(t_grid *grid, int nb, int i, int j);

#endif
