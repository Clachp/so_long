/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/28 16:49:35 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *file)
{
	int		fd;
	char	*line;
	char	*stash;
	
	if (check_argv(file) == 1)
		return (ft_putstr_fd("Unvalid map or input\n", 1), NULL);
	fd = open(file, O_RDONLY);
	if (fd < 1)
		return(ft_putstr_fd("Error opening file in get_map\n", 1), NULL);
	line = "";
	stash = ft_strdup("");
	while(line)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\n')
			break;
		stash = ft_strjoin(stash, line);
		free(line);
	}
	free(line);
	close(fd);
	return(ft_split(stash, '\n'));
}

void init_map (t_game *game, char *file)
{
    game->map = get_map(file);
	get_image(game);
	get_window_size(game);
	game->win = mlx_new_window(game->mlx, game->width, game->height, TITLE);
	put_images(game);    	
}

void free_map(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_window(game->mlx, game->win);
	while (*(game->map + i))
	{
		printf("map ads : %p\n", &game->map + i);
		free(game->map + i);
		i++;
	}
}

/*int main (int argc, char **argv)
{
	char **map = get_map(argv[1]);
	size_t	x = 0;
	size_t	y = 0;

	if (argc == 2)
	{
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
		printf("y = %ld\n x = %ld\n", y, x);
	}
	return(0);
}*/
