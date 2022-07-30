/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/30 20:05:50 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// la carte doit contenir au moins 1 sortie E, 1 item C et 1 position de départ P
//Carte rectangulaire
// Encadrée par des murs 1
// Retourner erreur de configuration
int check_line (char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (1);	
		i++;	
	}
	return (0);
}

int check_walls(char **map)
{
	int x;
    int y;
    
	if (check_line(*map) == 1)
		return (ft_putstr_fd("top wall missing\n", 1), 1);
	y = 0;
    while (*(map + y) != NULL)
	{
		x = 0;
		while (*(*(map + y) + x))
		{
			if (*(*(map + y)) != '1')
				return (ft_putstr_fd("left wall missing\n", 1), 1);
			if (*(*(map + y) + x + 1) == '\0' && *(*(map + y) + x) != '1')
				return (ft_putstr_fd("right wall missing\n", 1), 1);
			x++;
		}	
		y++;
	}
	if (check_line(*(map + y - 1)) == 1)
		return (ft_putstr_fd("bottom wall missing\n", 1), 1);
	return (ft_putstr_fd("walls ok\n", 1), 0);
}

int check_player_position (t_game *game)
{
	int x;
    int y;

    y = 0;
    while (game->map && *(game->map + y))
	{
		x = 0;
		while (*(*(game->map + y) + x))
		{
			if (*(*(game->map + y) + x) == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);	
}

int check_content(t_game *game)
{
	int x;
    int y;

    y = 0;
	game->coll = 0;
	game->exit = 0;
    while (game->map && *(game->map + y))
	{
		x = 0;
		while (*(*(game->map + y) + x))
		{
			if (*(*(game->map + y) + x) == 'C')
				game->coll++;
			if (*(*(game->map + y) + x) == 'E')
				game->exit++;
			x++;
		}
		y++;
	}
	if (check_player_position(game) == 0 || game->coll == 0 || game->exit == 0)
		return (ft_putstr_fd("Content missing\n", 1), 1);
	return (ft_putstr_fd("Content OK\n", 1), 0);
}

/*int check_input(char *argv)
{
    
}*/

int	check_map(t_game *game)
{
	if (check_walls(game->map) == 0 && check_content(game) == 0)
		return (0);
	else
		return (ft_putstr_fd("Invalid map\n", 1), 1);
}