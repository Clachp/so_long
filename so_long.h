/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:27:21 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/25 19:07:36 by cchapon          ###   ########.fr       */
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

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

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

char *get_map(char *file);
int draw_map(t_game *game, char *file);

#endif
