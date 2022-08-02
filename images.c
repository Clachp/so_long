/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:14:07 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/02 16:55:39 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_window(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (*(game->map + y) != NULL)
	{
		x = 0;
		while (*(*(game->map + y) + x))
			x++;
		//if (x != y)
		//	return (ft_putstr_fd("unequal lines", 1), 1);
		y++;
	}
	game->floor.img = mlx_xpm_file_to_image(game->mlx, "./assets/grass.xpm", \
	&game->floor.width, &game->floor.height);
	if (!game->floor.img)
		return (1);
	game->width = game->floor.width * x; // ne marche pas car game floor.width et floor.height ne sont pas initialises 
	game->height = game->floor.height * y;
	game->win = mlx_new_window(game->mlx, game->width, game->height, TITLE);
	if (game->width <= game->height)
		return (1);
	return (0);
}

int	get_floor(t_game *game, int x, int y)
{		
	mlx_put_image_to_window(game->mlx, game->win, game->floor.img, \
	x * game->floor.height, y * game->floor.width);
	return (0);
}

int	get_wall(t_game *game, int x, int y)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./assets/tree.xpm", \
	&game->wall.width, &game->wall.height);
	if (!game->floor.img)
		return (1);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->wall.img, x * game->wall.width, y * game->wall.height);
	return (0);
}

int	get_player(t_game *game, int x, int y)
{
	game->player.img = mlx_xpm_file_to_image(game->mlx, "./assets/rafou.xpm", \
	&game->player.width, &game->player.height);
	if (!game->floor.img)
		return (1);
	mlx_put_image_to_window(game->mlx, game->win, game->player.img, \
	x * game->player.width, y * game->player.height);
	return (0);
}

int	get_collectible(t_game *game, int x, int y)
{
	game->coll.img = mlx_xpm_file_to_image(game->mlx, "./assets/shoe.xpm", \
	&game->coll.width, &game->coll.height);
	if (!game->floor.img)
		return (1);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->coll.img, x * game->coll.width, y * game->coll.height);
	return (0);
}

int	get_exit(t_game *game, int x, int y)
{
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "./assets/venusaur.xpm", \
	&game->exit.width, &game->exit.height);
	if (!game->floor.img)
		return (1);
	mlx_put_image_to_window(game->mlx, game->win, \
	game->exit.img, x * game->exit.width, y * game->exit.height);
	return (0);
}

int	put_images(t_game *game)
{
	int	x;
	int	y;
 
	y = 0;
	while (*(game->map + y))
	{
		x = 0;
		while (*(*(game->map + y) + x))
		{
			if (*(*(game->map + y) + x) == '0')
				get_floor(game, x, y);
			/*if (*(*(game->map + y) + x) == '1')
				get_wall(game, x, y);
			if (*(*(game->map + y) + x) == 'P')
				get_player(game, x, y);
			if (*(*(game->map + y) + x) == 'C')
				get_collectible(game, x, y);
			if (*(*(game->map + y) + x) == 'E')
				get_exit(game, x, y);*/
			x++;
		}
		y++;
	}
	return (0);
}

void	destroy_images(t_game *game)
{
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->coll.img)
		mlx_destroy_image(game->mlx, game->coll.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
}
