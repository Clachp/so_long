/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:25:18 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/05 18:50:21 by cchapon          ###   ########.fr       */
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
	free(game->file);
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

	game.file = "";
	if (argc == 2)
	{
		game.file = check_input(argv[1]);
		if (game.file)
		{
			init_game(&game, game.file);
			mlx_loop(game.mlx);
		}
	}
	else
		throw_error("Wrong argument number\n");
	return (0);
}
