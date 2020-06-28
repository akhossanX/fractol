
#include "libft.h"

int		ft_iscntrl(int c)
{
	unsigned char	n;

	n = (unsigned char)c;
	return (n < 32 || n >= 127);
}
