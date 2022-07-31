/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:25:18 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/31 18:39:21 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char *file)
{
	game->mlx = mlx_init();
	init_map (game, file);
	return (0);
}

/*int end_game()
{
	
}*/

int	close_win(t_game *data)
{
	mlx_loop_end(data->mlx);
	destroy_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	//free_map(data);
	//free(data->mlx);
	//free(data);
	exit(0);
	return (0);
}

int handle_key_hook(int key, t_game *data)
{
	if(key == XK_Escape)
		close_win(data);
	return (0);
}

int main(int argc, char **argv)
{
	t_game	game;
	
	if (argc == 2)
	{
		init_game(&game, argv[1]);
		mlx_key_hook(game.win, handle_key_hook, &game); 
		mlx_hook(game.win, 17, 1L<<2, close_win, &game);
		mlx_loop(game.mlx);
	}
	else
		printf("Wrong argument number !\n");		
	return(0);
}
