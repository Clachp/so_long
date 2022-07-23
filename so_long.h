/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:27:21 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/23 19:16:39 by cchapon          ###   ########.fr       */
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
#include "lib/gnl/get_next_line.h"

#define WINDOW_WIDTH 200
#define WINDOW_HEIGHT 160

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*path;
	char	**map;
	int		x;
	int		y;
	int		blanck;
	int		wall;
	int		C;
	int		E;
	int		P;
}	t_game; 

int draw_map(t_game *game);

#endif
