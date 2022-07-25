/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/25 19:10:27 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//get_map permet de generer le tableau game->**map dans lequel je vais pouvoir dessiner
// je vais devoir faire le parsing dans cette fonction
char	*get_map(char *file)
{
	int 	fd;
	char 	*line;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	printf("%s\n", line);
	close(fd);
	return (line);
}

//je recupere la map[][] et je gere les erreurs
/*void	check_map(char **map)
{

}*/

/*void get_image(t_game *game)
{	
	int	i;

	game->img= mlx_xpm_file_to_image(game->mlx, "./tree.xpm", &i, &i);	
}*/

//je fais le parsing de la map
/*int draw_map(t_game *game)
{
	int	x;
	int	y;

	get_image(game);
	y = 0;
	while (game->map[y] y < 5)
	{
		x = 0;
		while (game->map[y][x] x < 5)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img, x*40, y*32);
			x++;
		}
		y++;
	}
	return (0);
}*/

/*int draw_map(t_game *game, char *file)
{
	int		y;

	game->map = get_map(file);
	y = 0;
	while (game->map[y])
	{
		printf("%s\n", game->map[y]);
		y++;
	}
	return (0);
}*/
