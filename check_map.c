/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/10 11:56:54 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(char **map)
{
	int	x;
	int	y;

	if (check_line(*map) == 1)
		return (1);
	y = 0;
	while (*(map + y) != NULL)
	{
		x = 0;
		while (*(*(map + y) + x))
		{
			if (*(*(map + y)) != '1')
				return (1);
			if (*(*(map + y) + x + 1) == '\0' && *(*(map + y) + x) != '1')
				return (1);
			x++;
		}
		if (map[y + 1] && (ft_strlen(map[y]) != ft_strlen(map[y + 1])))
			return (1);
		y++;
	}
	if (check_line(*(map + y - 1)) == 1)
		return (1);
	return (0);
}

int	check_player_position(t_game *game)
{
	int	x;
	int	y;

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
	throw_error("Player missing\n");
	return (0);
}

int	check_content(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->coll.nbr = 0;
	game->exit.nbr = 0;
	while (game->map && *(game->map + y))
	{
		x = 0;
		while (*(*(game->map + y) + x))
		{
			if (*(*(game->map + y) + x) == 'C')
				game->coll.nbr++;
			if (*(*(game->map + y) + x) == 'E')
				game->exit.nbr++;
			if (check_char(*(*(game->map + y) + x)) == 1)
				return (throw_error("Unknown character in map\n"), 1);
			x++;
		}
		y++;
	}
	if (check_player_position(game) == 0 || game->coll.nbr == 0 \
	|| game->exit.nbr == 0)
		return (1);
	return (0);
}

int	check_map(t_game *game)
{
	if (check_equal_lines(game->map) == 1)
		return (1);
	if (check_walls(game->map) == 1)
	{
		throw_error("Map must be surrounded by walls\n");
		return (1);
	}
	if (check_content(game) == 1)
	{
		if (game->coll.nbr == 0)
			throw_error("Collectibles missing\n");
		if (game->exit.nbr == 0)
			throw_error("No exit in map\n");
		return (1);
	}
	return (0);
}
