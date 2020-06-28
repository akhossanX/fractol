
#include "fractal.h"
#define ZOOM_IN		(5)
#define ZOOM_OUT	(4)

int		key_event(int key, t_fract *ol)
{
	t_mlx	*mlx;

	mlx = ol->mlx;
	if (key == ESCAPE)
	{
		mlx_destroy_image(mlx->ptr, mlx->img);
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(ol);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		mouse_event(int button, int x, int y, t_fract *ol)
{
	(void)x;
	(void)y;
	if (button == ZOOM_IN)
		ol->mlx->step -= 0.0005;
	else if (button == ZOOM_OUT)
		ol->mlx->step += 0.0005;
	if (button == ZOOM_IN || button == ZOOM_OUT)
	{
		render(ol);
		mlx_put_image_to_window(ol->mlx->ptr, ol->mlx->win, ol->mlx->img, 0, 0);
	}
	//ft_printf("mouse: %d\n", button);
	return (0);
}
