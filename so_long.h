/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:27:21 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/26 17:51:08 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <X11/X.h>
#include <stdio.h>
#include <X11/keysym.h>
#include "mlx/mlx.h"
#include "mlx/mlx_int.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <fcntl.h>

#define WIN_WIDTH 600
#define WIN_HEIGHT 400
#define TITLE "SO LONG"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*path;
	char	**map;
	char	*line;
	int		x;
	int		y;
	int		blanck;
	int		wall;
	int		C;
	int		E;
	int		P;
}	t_game; 

char **get_map(char *file);
int draw_map(t_game *game, char *file);
int get_height(char **map);

#endif
