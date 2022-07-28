/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:14:07 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/28 15:44:39 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_image(t_game *game)
{	
    game->grass.img = mlx_xpm_file_to_image(game->mlx, "./assets/grass.xpm", &game->grass.width, &game->grass.height);
    game->tree.img = mlx_xpm_file_to_image(game->mlx, "./assets/tree.xpm", &game->tree.width, &game->tree.height);
    game->shoe.img = mlx_xpm_file_to_image(game->mlx, "./assets/shoe.xpm", &game->shoe.width, &game->shoe.height);
    game->character.img = mlx_xpm_file_to_image(game->mlx, "./assets/rafou.xpm", &game->character.width, &game->character.height);
    game->ennemy.img = mlx_xpm_file_to_image(game->mlx, "./assets/venusaur.xpm", &game->ennemy.width, &game->ennemy.height);	
}

int get_window_size(t_game *game)
{
    int x;
    int y;
    int *px;
    int *py;
    
    px = &x;
    py =&y;
    y = 0;
    x = 0;
	while (*(game->map + y) != NULL)
	{
		x = 0;
		while (*(*(game->map + y) + x))
			x++;
		y++;
	}
    printf ("x = %d\ny = %d\n", x, y);
    game->width = game->grass.width  * *px;
    game->height = game->grass.height * *py;
    printf("game width : %d\n", game->width);
    printf("game height : %d\n", game->height);
    if (game->width <= game->height)
        return (1);
    return (0); 
}

void put_images(t_game *game)
{
    int x;
    int y;
    
    y = 0;
    while (*(game->map + y))
    {
        x = 0;
        while (*(*(game->map + y) + x))
        {
            if(*(*(game->map + y) + x) == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->grass.img, x * game->grass.height, y * game->grass.width);
            if(*(*(game->map + y) + x) == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->tree.img, x * game->tree.width, y * game->tree.height);
			if(*(*(game->map + y) + x) == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->character.img, x * game->character.width, y * game->character.height);
			if(*(*(game->map + y) + x) == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->shoe.img, x * game->shoe.width, y * game->shoe.height);
            if(*(*(game->map + y) + x) == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->shoe.img, x * game->shoe.width, y * game->shoe.height);
            x++;
        }
        y++;
    }
}

void destroy_images(t_game *game)
{
    mlx_destroy_image(game->mlx, game->grass.img);
    mlx_destroy_image(game->mlx, game->grass.img);
    mlx_destroy_image(game->mlx, game->grass.img);
    mlx_destroy_image(game->mlx, game->grass.img); 
}


//TODO : destroy images a la fermeture du programme 
//int	mlx_destroy_image(t_xvar *xvar, t_img *img)