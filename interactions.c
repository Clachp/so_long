/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/02 15:38:41 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_right(t_game *game, int x, int y)
{
	printf("x = %d y = %d\n", game->player.x, game->player.y);
	if (*(*(game->map + y) + x) == '1')
		return (ft_putstr_fd("Wall !\n", 1), 1);
	if (*(*(game->map + y) + x) == 'C')
		game->coll.nbr--;
	if (*(*(game->map + y) + x) == 'E' && game->coll.nbr == 0)
		printf("You won !");
	*(*(game->map + y) + x) = 'P';
	*(*(game->map + game->player.y) + game->player.x) = '0';
	return (0);
}

int	handle_key_hook(int key, t_game *game)
{
	if (key == XK_w || key == XK_W)
	{
		if (move_right(game, game->player.x, game->player.y - 1) == 0)
			game->player.y--;
	}
	if (key == XK_a || key == XK_A)
	{
		if (move_right(game, game->player.x, game->player.y + 1) == 0)
			game->player.y++;
	}
	if (key == XK_s || key == XK_S)
	{
		if (move_right(game, game->player.x - 1, game->player.y) == 0)
			game->player.x--;
	}
	if (key == XK_d || key == XK_D)
	{
		if (move_right(game, game->player.x + 1, game->player.y) == 0)
			game->player.x++;
	}
	if (key == XK_Escape)
		close_win(game);
	return (0);
}
