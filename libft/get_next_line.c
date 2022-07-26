/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:32:38 by cchapon           #+#    #+#             */
/*   Updated: 2022/06/13 16:54:56 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_one_line(char *line, char *buff)
{
	int	i;
	int	j;

	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	j = 0;
	while (buff[j] && line[i + j])
	{
		buff[j] = line[i + j];
		j++;
	}
	line[i] = '\0';
	buff[j] = '\0';
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		buff[BUFFER_SIZE + 1];
	int				r;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	r = BUFFER_SIZE;
	line = NULL;
	line = ft_gnl_strjoin(line, buff);
	while (to_end(line) == 0 && r == BUFFER_SIZE)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
			return (free(line), NULL);
		buff[r] = '\0';
		line = ft_gnl_strjoin(line, buff);
	}
	if (line[0] == 0)
		return (free(line), NULL);
	get_one_line(line, buff);
	return (line);
}
