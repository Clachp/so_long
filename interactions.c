/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/05 17:14:06 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(t_game *game, int x, int y)
{
	if (*(*(game->map + y) + x) == '1')
		throw_error("Wall !\n");
	if (*(*(game->map + y) + x) == 'C')
		game->coll.nbr--;
	if (*(*(game->map + y) + x) == 'E')
	{
		if (game->coll.nbr == 0)
			printf("You won in %d moves!\n", game->move);
		else
			printf("you lost\n");
		// lancer animation fin du jeu
		close_game(game);
	}
	*(*(game->map + y) + x) = 'P';
	*(*(game->map + game->player.y) + game->player.x) = '0';
	game->move++;
	printf("moves : %d\n", game->move);
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