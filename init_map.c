/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/04 19:41:01 by cchapon          ###   ########.fr       */
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
		return (ft_putstr_fd("Error opening file in get_map\n", 1), NULL);
	line = "";
	stash = ft_strdup("");
	while (line)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\n')
			break ;
		stash = ft_gnl_strjoin(stash, line);
		free(line);
	}
	close(fd);
	result = ft_split(stash, '\n');
	free(stash);
	return (result);
}

int	get_window(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (*(game->map + y) != NULL)
	{
		x = 0;
		while (*(*(game->map + y) + x))
			x++;
		if (game->map[y + 1] && \
		ft_strlen(game->map[y]) != ft_strlen(game->map[y + 1]))
			return (ft_putstr_fd("unequal lines", 1), 1);
		y++;
	}
	game->floor.img = mlx_xpm_file_to_image(game->mlx, "./assets/grass.xpm", \
	&game->floor.width, &game->floor.height);
	if (!game->floor.img)
		return (1);
	game->width = game->floor.width * x;
	game->height = game->floor.height * y;
	game->win = mlx_new_window(game->mlx, game->width, game->height, TITLE);
	if (game->width <= game->height)
		return (1);
	return (0);
}

int	get_images(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "./assets/tree.xpm", \
	&game->wall.width, &game->wall.height);
	if (!game->wall.img)
		return (1);
	game->coll.img = mlx_xpm_file_to_image(game->mlx, "./assets/shoe.xpm", \
	&game->coll.width, &game->coll.height);
	if (!game->coll.img)
		return (1);
	game->player.img = mlx_xpm_file_to_image(game->mlx, "./assets/rafou.xpm", \
	&game->player.width, &game->player.height);
	if (!game->floor.img)
		return (1);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "./assets/venusaur.xpm", \
	&game->exit.width, &game->exit.height);
	if (!game->exit.img)
		return (1);
	return (0);
}

int	put_images(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (*(game->map + y))
	{
		x = 0;
		while (*(*(game->map + y) + x))
		{
			if (*(*(game->map + y) + x) == '0')
				get_floor(game, x, y);
			if (*(*(game->map + y) + x) == '1')
				get_wall(game, x, y);
			if (*(*(game->map + y) + x) == 'P')
				get_player(game, x, y);
			if (*(*(game->map + y) + x) == 'C')
				get_collectible(game, x, y);
			if (*(*(game->map + y) + x) == 'E')
				get_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	init_map(t_game *game, char *file)
{
	game->map = get_map(file);
	if (!game->map)
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
