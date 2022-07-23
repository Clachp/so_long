/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/23 19:34:59 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_image(t_game *game)
{	
	int	i;

	game->img= mlx_xpm_file_to_image(game->mlx, "./tree.xpm", &i, &i);	
}

int draw_map(t_game *game)
{
	int	i;
	int	j;

	get_image(game);

	j = 0;
	while (/*game->map[j]*/ j < 5)
	{
		i = 0;
		while (/*game->map[j][i]*/ i < 5)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img, i*40, j*32);
			i++;
		}
		j++;
	}
	return (0);
}
