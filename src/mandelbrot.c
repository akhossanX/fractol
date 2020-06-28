
#include "fractal.h"

void	fract_mandelbrot(t_thread *th)
{
	long double complex	z;
	long double complex	c;
	int				i;

	th->color = palette[0];
	c = th->x + I * th->y;
	z = 0.;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		if (pow(cabsl(z), 2.0) > 4)
		{
			th->color = get_it_color(i);
			return ;
		}
		z = cpowl(z, (long complex double)2.0) + c;
		i++;
	}
}

unsigned int	get_v_color(double v)
{

	return (8388607 * (1 + cos(6.28 * v)));//0xffffff / 2 = 8388607
	/*
	unsigned long long	index;

	index = (unsigned long long)(v * 1000);
	return (palette[index % PALETTE_NCOLORS]);	
	*/
}/*
void	fract_mandelbrot(t_thread *th)
//int		get_vpixel_color(double x, double y)
{
	double complex	z;
	double complex	c;
	int				i;
	double			v;
	int				power;
	double			sqrmod;

	c = th->x + I * th->y;
	th->color = palette[0];
	z = 0.;
	i = 0;
	power = 1;
	while (i < MAX_ITERATIONS)
	{
		sqrmod = pow(cabs(z), 2.0);
		if (sqrmod > 1000000.)
		{
			v = clog(sqrmod) / power;
			th->color = get_v_color(log(v)/ 10000);
			return ;
		}
		z = cpow(z, (complex double)2.0) + c;
		power *= 2;
		i++;
	}
}
*/
