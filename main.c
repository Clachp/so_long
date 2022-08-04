/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:25:18 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/04 20:15:17 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char *file)
{
	game->mlx = mlx_init();
	game->move = 0;
	init_map (game, file);
	handle_mlx_hooks(game);
	return (0);
}

int	close_game(t_game *game)
{
	free_map(game->map);
	destroy_images(game);
	destroy_window(game);
	mlx_loop_end(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_game(&game, argv[1]);
		mlx_loop(game.mlx);
	}
	else
		printf("Wrong argument number !\n");
	return (0);
}
