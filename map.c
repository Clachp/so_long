/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/02 16:55:26 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *file)
{
	int		fd;
	char	*line;
	char	*stash;

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
	if (check_input(file) == 1)
	{
		ft_putstr_fd("Unvalid map or input\n", 1);
		exit(0); 
	}
	game->map = get_map(file);
	if (check_map(game) == 0)
	{
		get_window(game);
		put_images(game);		
	}
}

void free_map(char **map)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (map[y][x])
	{
		free(map[y]);
		y++;
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
