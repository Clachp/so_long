/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/28 17:00:51 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// la carte doit contenir au moins 1 sortie E, 1 item C et 1 position de départ P
//Carte rectangulaire
// Encadrée par des murs 1
// Retourner erreur de configuration

int check_walls(char **map)
{
    int x;
    int y;
    
    y = 0;
    while (*(map + y) != NULL)
	{
		x = 0;
		while (*(*(map + y) + x))
		{
			if (**map + x != '1')
				return (ft_putstr_fd("top wall missing\n", 1), 1);
			if (*(*(map + y)) != '1')
				return (ft_putstr_fd("left wall missing\n", 1), 1);
			if (*(*(map + y) + x + 1) == '\0' && *(*(map + y) + x) != '1')
				return (ft_putstr_fd("right wall missing\n", 1), 1);
			//if (*(map + y + 1) == NULL &&  )
			x++;
		}	
		y++;
	}
	return (ft_putstr_fd("walls ok\n", 1), 0);
}

/*int check_player_position(t_game *game)
{
	int x;
    int y;
    
    y =0;
    while (game->map && *(game->map + y))
		{
			x = 0;
			while (*(*(game->map + y) + x))
			{
				if (*(*(game->map + y) + x) == 'P')
				{
					game->px = x;
					game->py = y;
					return (1);
				}
				x++;
			}
			y++;
		}
		return (0);
}

int check_content(char **map)
{
    int x;
    int y;
    
    y =0;
    while (map && *(map + y))
		{
			x = 0;
			while (*(*(map + y) + x))
			{
				if (*(*(map + y) + x) == 'P')
				x++;
			}
		printf("\n");
			y++;
		}
    
}

int check_input(char *argv)
{
    
}

int	check_map(char **map, char *file)
{
	int x;
	int	y;

	map = get_map(file);
	y = 0;
	while (*(map +y) != NULL)
	{
		x = 0;
		while (*(*(map + y) + x))
		{
			x++;
		}
		y++;
	}
	return (0);
}*/