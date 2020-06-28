
#include "fractal.h"

unsigned int	get_it_color(int it)
{
	unsigned int	color;
	char			s[4];

	s[0] = 0;
	s[1] = sin(0.3 * (t_ldbl)it);
	s[2] = sin(0.3 * (t_ldbl)it + 3) * 127 + 128;
	s[3] = sin(0.3 * (t_ldbl)it + 3) * 127 + 128;
	color = *(int *)s;
	return (color);
}

void	set_pix_color(t_mlx *mlx, t_ldbl x, t_ldbl y, int color)
{
	int		i;
	int		j;

	i = (int) ((x / mlx->step) + XOFFSET);
	j = (int) ((y / mlx->step) + YOFFSET);
	if (i >= 0 && i < WIDTH && j >= 0 && j < HEIGTH)
		mlx->data[i + j * WIDTH] = (int)mlx_get_color_value(mlx->ptr, color);
}
