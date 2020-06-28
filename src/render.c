
#include "fractal.h"
#define TH_MAGNITUDE	(HEIGTH / THREADS)

void	map_xy_to_z(int i, int j, t_thread *th)
{
	t_ldbl	step;

	step = th->mlx->step;
	th->x = (i  - WIDTH / 2) * step;
	th->y = (j  - HEIGTH / 2) * step;
}

void	*render_thd(void *thd)
{
	int			i;
	int			j;
	int			y0;
	int			yend;
	t_thread	*th;

	th = (t_thread *)thd;
	i = 0;
	y0 = (th->nthd * TH_MAGNITUDE); 
	yend = y0 + TH_MAGNITUDE;
	while (i < WIDTH)
	{
		j = y0;
		while (j < yend)
		{
			//ft_printf("(%d,%d) ", i, j);
			map_xy_to_z(i, j, th);
			//th->nthd == 0 ? ft_printf("(%lf,%lf)", th->x, th->y) : 0;
			th->fract_fn(th);
			th->mlx->data[i + j * WIDTH] = (int)mlx_get_color_value(\
				th->mlx->ptr, th->color);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	render(t_fract *ol)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		ol->threads[i].nthd = i;
		ol->threads[i].mlx = ol->mlx;
		ol->threads[i].fract_fn = ol->fract_fn;
		pthread_create(&ol->threads[i].thd, NULL, render_thd, &ol->threads[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
	{
		pthread_join(ol->threads[i].thd, NULL);
		i++;
	}
}

