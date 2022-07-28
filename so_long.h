/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:27:21 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/28 15:48:14 by cchapon          ###   ########.fr       */
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
	int		width;
	int		height;
	t_pic	grass;
	t_pic	tree;
	t_pic	shoe;
	t_pic	ennemy;
	t_pic	character;
}	t_game; 

char **get_map(char *file);
int draw_map(t_game *game, char *file);
void get_image(t_game *game);
void init_map (t_game *game, char *file);
int get_window_size(t_game *game);
void put_images(t_game *game);
void free_map(t_game *game);


#endif
