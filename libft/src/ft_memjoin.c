
#include "libft.h"

void	*ft_memjoin(void *s1, void *s2, size_t n1, size_t n2)
{
	size_t	size;
	void	*mem;

	size = n1 + n2;
	if (size == 0)
		return (0);
	mem = ft_memalloc(size);
	ft_memmove(mem, s1, n1);
	ft_memmove(mem + n1, s2, n2);
	return (mem);
}
