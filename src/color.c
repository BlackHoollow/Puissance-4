/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 21:41:09 by aclot             #+#    #+#             */
/*   Updated: 2016/02/28 22:19:52 by aclot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	print_token(int player)
{
	if (player == 0)
	{
		ft_putstr("\x1b[30m");
		ft_putstr(" ");
	}
	else if (player == 1)
	{
		ft_putstr("\x1b[34m");
		ft_putstr("O");
	}
	else if (player == 2)
	{
		ft_putstr("\x1b[31m");
		ft_putstr("X");
	}
	ft_putstr("\x1b[0m");
}
