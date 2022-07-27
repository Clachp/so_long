/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/27 18:42:13 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TODO fonction a terminer pour checker format de l'input
int	check_argv(char	*file)
{
	if (!file)
		return (1);
	return(0);
}

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
	while(line != NULL)
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
