/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <cchapon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:27:21 by cchapon           #+#    #+#             */
/*   Updated: 2022/08/04 20:10:27 by cchapon          ###   ########.fr       */
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
	int		move;
	t_pic	floor;
	t_pic	wall;
	t_pic	coll;
	t_pic	player;
	t_pic	exit;
}	t_game; 

int check_map(t_game *game);
int check_line (char *line);
int check_char(char c);
int check_input(char *file);
int	put_images(t_game *game);
void init_map (t_game *game, char *file);
void handle_mlx_hooks(t_game *game);
void free_map(char **map);
void destroy_images(t_game *game);
void	destroy_window(t_game *game);
int	close_game(t_game *game);
void	get_floor(t_game *game, int x, int y);
void	get_wall(t_game *game, int x, int y);
void	get_player(t_game *game, int x, int y);
void	get_collectible(t_game *game, int x, int y);
void	get_exit(t_game *game, int x, int y);

#endif
