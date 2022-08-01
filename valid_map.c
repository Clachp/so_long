/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/01 15:03:53 by cchapon          ###   ########.fr       */
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
				game->player.x = x;
				game->player.y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);	
}

int check_char(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E')
		return (1);
	return (0);
}

int check_content(t_game *game)
{
	int x;
    int y;

    y = 0;
	game->coll.nbr = 0;
	game->exit.nbr = 0;
    while (game->map && *(game->map + y))
	{
		x = 0;
		while (*(*(game->map + y) + x))
		{
			if (check_char(*(*(game->map + y) + x)) == 1)
				return (1);
			if (*(*(game->map + y) + x) == 'C')
				game->coll.nbr++;
			if (*(*(game->map + y) + x) == 'E')
				game->exit.nbr++;
			x++;
		}
		y++;
	}
	if (check_player_position(game) == 0 || game->coll.nbr == 0 || game->exit.nbr == 0)
		return (ft_putstr_fd("Content missing\n", 1), 1);
	return (ft_putstr_fd("Content OK\n", 1), 0);
}

int check_input(char *arg)
{
    char	*ber;

	ber = ft_strnstr(arg, ".ber", ft_strlen(arg));
	if (ber)
	{
		if (ber == arg + ft_strlen(arg) - 4)
			return (0);
	}
	return (ft_putstr_fd("wrong input format", 1), 1);
}

int	check_map(t_game *game)
{
	if (check_walls(game->map) == 0 && check_content(game) == 0)
		return (0);
	else
		return (ft_putstr_fd("Invalid map\n", 1), 1);
}