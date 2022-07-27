/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:14:07 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/27 19:13:41 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_image(t_game *game)
{	
	game->tree.img = mlx_xpm_file_to_image(game->mlx, "./assets/tree.xpm", &game->tree.width, &game->tree.height);
    game->grass.img = mlx_xpm_file_to_image(game->mlx, "./assets/grass.xpm", &game->tree.width, &game->tree.height);
    	
}

void init_map (t_game *game, char *file)
{
    int x;
    int y;
    
    game->map = get_map(file);
    y = 0;
    while (*(game->map + y))
    {
        x = 0;
        while (*(*(game->map + y) + x))
        {
            if(*(*(game->map + y) + x) == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->grass.img, x*40, y*32);
            if(*(*(game->map + y) + x) == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->tree.img, x*40, y*32);
            x++;
        }
        y++;
    }
}

//TODO : destroy images a la fermeture du programme 
//int	mlx_destroy_image(t_xvar *xvar, t_img *img)