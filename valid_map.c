/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/28 17:00:51 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_walls(char **map)
{
    int x;
    int y;
    
    y =0;
    while (*(map + y) != NULL)
		{
			x = 0;
			while (*(*(map + y) + x))
			{
				printf("%c", *(*(map + y) + x));
				x++;
			}
		printf("\n");
			y++;
		}
}

int check_content(char **map)
{
    
    
}

int check_input(char *argv)
{
    
}

int	check_map(char **map, char *file)
{
	int x;
	int	y;

	map = get_map(file);
	y = 0;
	while (*(map +y) != NULL)
	{
		x = 0;
		while (*(*(map + y) + x))
		{
			x++;
		}
		y++;
	}
	return (0);
}