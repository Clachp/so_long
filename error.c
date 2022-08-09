/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:27:17 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/09 18:23:30 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    throw_error(char *message)
{
    ft_putstr_fd("ERROR\n", 1);
    ft_putstr_fd(message, 1);
    exit (1);
}

void    move_nbr(int nbr)
{
    if (nbr == 1)
    {
        ft_putnbr_fd(nbr, 1);
        ft_putstr_fd(" move\n", 1);
    }
    ft_putnbr_fd(nbr, 1);
    ft_putstr_fd(" moves\n", 1);
}

void    score_message(t_game *game)
{
    
    ft_putstr_fd("You won in ", 1);
    ft_putnbr_fd(game->move, 1);
    ft_putstr_fd(" moves !\n", 1);
}

