/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:27:21 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/27 19:10:19 by cchapon          ###   ########.fr       */
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

#define WIN_WIDTH 400
#define WIN_HEIGHT 192
#define TITLE "SO LONG"

typedef struct s_pic {
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_pic;

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*path;
	char	**map;
	char	*line;
	int		x;
	int		y;
	t_pic	grass;
	t_pic	tree;
}	t_game; 

char **get_map(char *file);
int draw_map(t_game *game, char *file);
void get_image(t_game *game);
void init_map (t_game *game, char *file);


#endif
