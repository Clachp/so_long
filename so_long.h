/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:27:21 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/22 19:45:56 by cchapon          ###   ########.fr       */
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
#include "lib/libft/libft.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 500

#define WIDTH 10
#define HEIGHT 10

typedef struct s_data
{
	void *mlx;
	void *win;
}	t_data;

typedef struct s_tree
{
	void *mlx;
	void *img;
	char *path;
	int width;
	int height;
}	t_tree;

#endif
