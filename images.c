/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:14:07 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/01 18:08:06 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_image(t_game *game)
{	
        game->floor.img = mlx_xpm_file_to_image(game->mlx, "./assets/grass.xpm", \
        &game->floor.width, &game->floor.height);
        game->wall.img = mlx_xpm_file_to_image(game->mlx, "./assets/tree.xpm", \
        &game->wall.width, &game->wall.height);
        game->coll.img = mlx_xpm_file_to_image(game->mlx, "./assets/shoe.xpm", \
        &game->coll.width, &game->coll.height);
        game->player.img = mlx_xpm_file_to_image(game->mlx, "./assets/rafou.xpm", \
        &game->player.width, &game->player.height);
        game->exit.img = mlx_xpm_file_to_image(game->mlx, "./assets/venusaur.xpm", \
        &game->exit.width, &game->exit.height);
        if (!game->floor.img || !game->wall.img || !game->coll.img || !game->player.img || !game->exit.img)
            close_win(game);
        printf ("Get images ok\n");
}
// SEGV s'il y a un probleme avec le chargement des images : erreur a gerer dans get-image 

int get_window(t_game *game)
{
    int x;
    int y;

    y = 0;
    x = 0;
	while (*(game->map + y) != NULL)
	{
		x = 0;
		while (*(*(game->map + y) + x))
			x++;
       // if(x != ft_strlen(game->map[y]))
         //   return (ft_pustrs("Wrong map format", 1), 1);
		y++;
	}
    printf ("x = %d\ny = %d\n", x, y);
    game->width = game->floor.width  * x;
    game->height = game->floor.height * y;
    game->win = mlx_new_window(game->mlx, game->width, game->height, TITLE);
    printf("game width : %d\n", game->width);
    printf("game height : %d\n", game->height);
    printf("getwindow size ok");
    if (game->width <= game->height)
        return (1);
    return (0); 
}

int put_images(t_game *game)
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
                mlx_put_image_to_window(game->mlx, game->win, \
                game->floor.img, x * game->floor.height, y * game->floor.width);
            if(*(*(game->map + y) + x) == '1')
                mlx_put_image_to_window(game->mlx, game->win, \
                game->wall.img, x * game->wall.width, y * game->wall.height);
			if(*(*(game->map + y) + x) == 'P')
                mlx_put_image_to_window(game->mlx, game->win, \
                game->player.img, x * game->player.width, y * game->player.height);
			if(*(*(game->map + y) + x) == 'C')
                mlx_put_image_to_window(game->mlx, game->win, \
                game->coll.img, x * game->coll.width, y * game->coll.height);
            if(*(*(game->map + y) + x) == 'E')
                mlx_put_image_to_window(game->mlx, game->win, \
                game->exit.img, x * game->exit.width, y * game->exit.height);
            x++;
        }
        y++;
    }
    return (0);
}

void destroy_images(t_game *game)
{
    if (game->floor.img)
        mlx_destroy_image(game->mlx, game->floor.img);
    if (game->wall.img)
        mlx_destroy_image(game->mlx, game->wall.img);
    if (game->player.img)
        mlx_destroy_image(game->mlx, game->player.img);
    if (game->coll.img)
        mlx_destroy_image(game->mlx, game->coll.img);
    if (game->exit.img)
        mlx_destroy_image(game->mlx, game->exit.img);
}


//TODO : destroy images a la fermeture du programme 
//int	mlx_destroy_image(t_xvar *xvar, t_img *img)