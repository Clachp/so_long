/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:27:21 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/31 18:49:25 by cchapon          ###   ########.fr       */
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
	int		nbr;
	int 	x;
	int		y;
}	t_pic;

typedef struct s_game {
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	t_pic	floor;
	t_pic	wall;
	t_pic	coll;
	t_pic	ennemy;
	t_pic	player;
	t_pic	exit;
}	t_game; 

char **get_map(char *file);
int draw_map(t_game *game, char *file);
void get_image(t_game *game);
void init_map (t_game *game, char *file);
int get_window(t_game *game);
void put_images(t_game *game);
void free_map(t_game *game);
int check_map(t_game *game);
void end_game(t_game *game);
void destroy_images(t_game *game);
int	close_win(t_game *data);
#endif
