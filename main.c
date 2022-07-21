/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:35:52 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/21 13:36:46 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data {
	void	*img;
	char	*adr;
	int		pixel;
	int		line;
	int		end;		
} 	t_data;

int main(void)
{
	void	*mlx;
   	void    *win_ptr;
	void	*img;
	int		pixel;
	int		*color;

	color = 
	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, 400, 400, "My fenetre");
	img = mlx_new_image(mlx, 1920, 1080);
	pixel = mlx_pixel_put (mlx, win_ptr, 0, 0, ));	
	mlx_put_image_to_window(mlx, win_ptr, img, 0, 0);
    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
