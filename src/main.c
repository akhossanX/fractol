
#include "fractal.h"

t_fract_fn	get_fractol_fn(char **av)
{
	if (av[1] == NULL)
		return (NULL);
	if (ft_strequ(av[1], JULIA))
		return (fract_julia);
	else if (ft_strequ(av[1], MANDELBROT))
		return (fract_mandelbrot);
	return (NULL);
}

void	fractol_exit(t_fract *ol)
{
	mlx_destroy_image(ol->mlx->ptr, ol->mlx->img);
	mlx_destroy_window(ol->mlx->ptr, ol->mlx->win);
	free(ol);
	exit(1);
}

void	fractol_usage(t_fract *ol, char **av)
{
	ft_dprintf(2, "Usage:\n");
	ft_dprintf(2, "\t%s [fractal_name]\n", av[0]);
	free(ol->mlx);
	free(ol);
	exit(1);
}

t_fract		*fractol_init(char **av)
{
	t_fract		*ol;

	if (!(ol = (t_fract *)ft_memalloc(sizeof(t_fract))) ||
		!(ol->mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx))))
	{
		ft_dprintf(STDERR, "%s: %s\n", av[0], strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (!(ol->fract_fn = get_fractol_fn(av)))
		fractol_usage(ol, av);
	ol->mlx->ptr = mlx_init();
	ol->mlx->win = mlx_new_window(ol->mlx->ptr, WIDTH, HEIGTH, "1337 Fractal");
	ol->mlx->img = mlx_new_image(ol->mlx->ptr, WIDTH, HEIGTH);
	ol->mlx->data = (int *)mlx_get_data_addr(ol->mlx->img, \
		&ol->mlx->bpp, &ol->mlx->szln, &ol->mlx->endian);
	ol->mlx->step = DEFAULT_STEP;
	return (ol);
}

int		main(int ac, char **av)
{
	t_fract	*ol;
	t_mlx	*mlx;

	(void)ac;
	ol = fractol_init(av);
	mlx = ol->mlx;
	render(ol);
	//draw_fractal(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	ft_printf("bpp: %d, szln: %d, endian: %d\n", mlx->bpp, mlx->szln, mlx->endian);
	mlx_key_hook(mlx->win, key_event, ol);
	mlx_mouse_hook(mlx->win, mouse_event, ol);
	mlx_loop(mlx->ptr);
	return (0);
}
