/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/10 12:03:02 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_exit(t_game *game, int x, int y)
{
	if (game->coll.nbr == 0)
	{
		*(*(game->map + y) + x) = 'P';
		*(*(game->map + game->player.y) + game->player.x) = '0';
		score_message(game);
		close_game(game);
	}
	else
	{
		ft_putstr_fd("You misssed some collectibles !\n", 1);
		return (1);
	}
	return (0);
}

int	move_player(t_game *game, int x, int y)
{
	if (*(*(game->map + y) + x) == '1')
	{
		ft_putstr_fd("Wall !\n", 1);
		return (1);
	}
	if (*(*(game->map + y) + x) == 'C')
		game->coll.nbr--;
	if (*(*(game->map + y) + x) == 'E')
	{
		if (handle_exit(game, x, y) == 1)
			return (1);
	}
	*(*(game->map + y) + x) = 'P';
	*(*(game->map + game->player.y) + game->player.x) = '0';
	game->move++;
	move_nbr(game->move);
	return (0);
}

int	handle_key_hook(int key, t_game *game)
{
	if (key == XK_w || key == XK_W)
	{
		if (move_player(game, game->player.x, game->player.y - 1) == 0)
			game->player.y--;
	}
	if (key == XK_a || key == XK_A)
	{
		if (move_player(game, game->player.x, game->player.y + 1) == 0)
			game->player.y++;
	}
	if (key == XK_s || key == XK_S)
	{
		if (move_player(game, game->player.x - 1, game->player.y) == 0)
			game->player.x--;
	}
	if (key == XK_d || key == XK_D)
	{
		if (move_player(game, game->player.x + 1, game->player.y) == 0)
			game->player.x++;
	}
	if (key == XK_Escape)
		close_game(game);
	return (0);
}

void	handle_mlx_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, put_images, game);
	mlx_key_hook(game->win, handle_key_hook, game);
	mlx_hook(game->win, 17, 1L << 2, close_game, game);
}
