/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/01 18:04:21 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// move up : y--
void move_right (t_game *game)
{

    int x;
    int y;
    
    printf("x = %d y = %d\n", game->player.x, game->player.y);
    x = game->player.x;
    y = game->player.y;
    x++;

    if(*(*(game->map + y) + x) == '0')
    {
        *(*(game->map + y) + x) = 'P';
        *(*(game->map + y) + x -1) = '0';
        game->player.x++;
        // game->player.y;
    }
/*    if(*(*(game->map + y) + x) == '1')

    if(*(*(game->map + y) + x) == 'P')

    if(*(*(game->map + y) + x) == 'C')

    if(*(*(game->map + y) + x) == 'E')*/
}
int handle_key_hook(int key, t_game *data)
{
	if (key == XK_w || key == XK_W)
    {
        printf("go up\n");    
    }		
	if (key == XK_a || key == XK_A)
		printf("go down\n");
	if (key == XK_s || key == XK_S)
		printf("go left\n");
	if (key == XK_d ||key == XK_D)
    {
        printf("go right\n");
       move_right(data);
    }
	if(key == XK_Escape)
		close_win(data);
	return (0);
}