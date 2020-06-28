
#ifndef __FRACTAL_H__
#define __FRACTAL_H__

#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <mlx.h>
#include <errno.h>
#include <pthread.h>
#include "libft.h"

#define WIDTH			(1000)
#define HEIGTH			(700)

#define JULIA			"julia"
#define MANDELBROT		"mandelbrot"

#define	ESCAPE			(65307)
#define	LBUTON			(1)

#define DEFAULT_STEP	(0.01034)
#define BLACK			(0X000000)
#define WHITE			(0XFFFFFF)
#define XOFFSET			(WIDTH / 2)
#define YOFFSET			(HEIGTH / 2)

#define MAX_ITERATIONS	(200)

#define XBEGIN			(-2.0)
#define XEND			(2.0)
#define YBEGIN			XBEGIN	
#define YEND			XEND

#define PALETTE_NCOLORS	(30)

#define THREADS			(4)

typedef long double	t_ldbl;

extern unsigned int	palette[];

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			szln;
	int			endian;
	t_ldbl		step;//for scaling
}				t_mlx;

typedef struct s_thread	t_thread;

typedef void	(*t_fract_fn)(t_thread *);

struct	s_thread
{
	pthread_t	thd;
	int			nthd;
	t_ldbl		x;
	t_ldbl		y;
	int			color;
	t_mlx		*mlx;
	t_fract_fn	fract_fn;//fractal function handler(drawer)
};

typedef struct	s_fract
{
	t_mlx		*mlx;//mlx data
	t_thread	threads[THREADS];
	t_fract_fn	fract_fn;//fractal function handler(drawer)
}				t_fract;

int		key_event(int key, t_fract *ol);
int		mouse_event(int button, int x, int y, t_fract *ol);
void	set_pix_color(t_mlx *mlx, t_ldbl x, t_ldbl y, int color);
void	draw_fractal(t_mlx *mlx);

void	fract_mandelbrot(t_thread *thd);
void	fract_julia(t_thread *thd);
void	render(t_fract *ol);
unsigned int	get_it_color(int it);
unsigned int	get_v_color(double v);

#endif
