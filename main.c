/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:25:18 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/27 18:53:57 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *data)
{
	mlx_loop_end(data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
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
	t_game	*game;
	
	game = (t_game*)malloc(sizeof (t_game));
	if (argc == 2)
	{
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
		get_image(game);
		init_map(game, argv[1]);
		mlx_key_hook(game->win, handle_key_hook, game); 
		mlx_hook(game->win, 17, 1L<<2, close_win, game);
		mlx_loop(game->mlx);
	}
	else
		printf("Wrong argument number !\n");
	free(game);
	return(0);
}

/*int main (void)
{
	char*line;

	line = get_map("./assets/map.ber");
	printf("%s", line);
	free(line);
	return (0);
}*/
