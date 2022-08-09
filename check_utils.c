/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:19:37 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/09 12:14:34 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_char(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E')
		return (1);
	return (0);
}

char	*check_input(char *input)
{
	char	*ber;
	char	*file;

	ber = ft_strnstr(input, ".ber", ft_strlen(input));
	file = ft_strjoin("map/", input);
	if (ber != input + ft_strlen(input) - 4)
	{
		free(file);
		throw_error("Wrong input format\n");
		return (NULL);
	}
	return (file);
}

int	check_equal_lines(char **map)
{
	int	y;

	y = 0;
	if (!map[y])
	{
		throw_error("Empty map\n");
		return (1);
	}
	while (map[y] != NULL)
	{
		if (map[y + 1] && (ft_strlen(map[y]) != ft_strlen(map[y + 1])))
		{
			throw_error("unequal lines\n");
			return (1);
		}		
		y++;
	}
	return (0);
}
