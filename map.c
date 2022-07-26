/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/26 17:46:17 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	get_height(char **map)
{
	size_t	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

/*char	*get_map(char *file)
{
	int 	fd;
	char 	*line;
	char	*temp;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	temp = get_next_line(fd);
	line = ft_strdup(temp);
 	free(temp);	
	close(fd);
	return (line);
}*/

char	**get_map(char *file)
{
	int 	fd;
	char 	**map;
	char	*line;
	int		y;
	
	y = 0;
	line = "";
	map[y] = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (line != NULL)
	{
		line = get_next_line(fd);
		map[y] = ft_strdup(line);
		printf("map[%d] = %s\n", y, map[y]);
 		free(line);
		y++;
	}
	printf("y = %d\n", y);
	free(line);
	close(fd);
	return (map);
}

void get_image(t_game *game)
{	
	int	i;
	
	game->img= mlx_xpm_file_to_image(game->mlx, "./assets/tree.xpm", &i, &i);	
}

/*int draw_map(t_game *game, char *file)
{
	size_t	x;
	size_t	y;

	get_image(game);
	game->line = get_map(file);
	x = 0;
	printf("len de game->line dans draw_map : %ld\n", ft_strlen(game->line));
	while (x < ft_strlen(game->line) - 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img, x*40, 32);
		x++;
	}
	free(game->line);
	return (0);
}*/
// **map n'est pas une string donc on ne peut pas utiliser ft_strlen

int draw_map(t_game *game, char *file)
{
	size_t	x;
	size_t	y;

	get_image(game);
	game->map = get_map(file);
	y = 0;
	while (y < get_height(game->map) - 1)
	{
		x = 0;
		while (x < ft_strlen(game->map[y]) - 1)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img, x*40, y*32);
			x++;
		}
		y++;
	}
	return (0);
}
