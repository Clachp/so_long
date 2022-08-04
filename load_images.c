/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:14:07 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/04 19:44:10 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_floor(t_game *game, int x, int y)
{		
	mlx_put_image_to_window(game->mlx, game->win, game->floor.img, \
	x * game->floor.height, y * game->floor.width);
}

void	get_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->wall.img, x * game->wall.width, y * game->wall.height);
}

void	get_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->player.img, \
	x * game->player.width, y * game->player.height);
}

void	get_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->coll.img, x * game->coll.width, y * game->coll.height);
}

void	get_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
	game->exit.img, x * game->exit.width, y * game->exit.height);
}
