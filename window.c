/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchapon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:25:18 by cchapon           #+#    #+#             */
/*   Updated: 2022/07/21 17:25:36 by cchapon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

int	close_win(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_loop_end(data->mlx);
	}
	return (0);
}

int main(void)
{
	t_data	window;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, \
	"SO LONG");
	mlx_hook(window.win, KeyPress, KeyPressMask, &close_win, &window);
	mlx_loop(window.mlx);
	mlx_destroy_display(window.mlx);
	free(window.mlx);
}
