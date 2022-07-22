/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:25:18 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/22 19:54:08 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_data *data)
{
	mlx_loop_end(data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int main(void)
{
	t_data	game;
	t_tree	img;

	img.path = "./tree.xpm";
	img.width = WIDTH;
	img.height = HEIGHT;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, \
	"SO LONG");
	img.img = mlx_xpm_file_to_image(game.mlx, img.path, &img.width, &img.height);
	mlx_put_image_to_window(game.mlx, game.win, img.img, 0, 0);
	mlx_key_hook(game.mlx, close_win, &game); 
//	mlx_hook(game.win, 17, 1L<<2, close_win, &game);
	mlx_loop(game.mlx);
	return (0);
}
