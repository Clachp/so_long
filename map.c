/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/04 17:41:42 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char *file)
{
	int		fd;
	char	*line;
	char	*stash;
	char	**result;
	
	if (check_input(file) == 1)
		return (ft_putstr_fd("wrong input format\n", 1), NULL);
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
		stash = ft_gnl_strjoin(stash, line);
		free(line);
	}
	close(fd);
	result = ft_split(stash, '\n');
	free(stash);
	return(result);
}

void init_map (t_game *game, char *file)
{
	game->map = get_map(file);
	if(!game->map)
	{
		printf("error getting map\n");
		exit(1);
	}	
	if (check_map (game) == 1)
	{
		free_map(game->map);
		exit(1);
	}
	if (check_map(game) == 0)
	{
		get_window(game);
		get_images(game);
		put_images(game);	
	}
}

void free_map(char **map)
{
	int	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	// printf("map[0] : %s\n", map[0]);
	//printf("map[0] : %s\n", map[0]);
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
