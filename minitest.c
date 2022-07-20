#include <stdlib.h>
#include "mlx_linux/mlx.h"

int main(void)
{
	void	*mlx_ptr;
    void    *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 400, 400, "My fenetre");
    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}