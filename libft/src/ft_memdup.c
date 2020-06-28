
#include "libft.h"

void	*ft_memdup(const void *s, size_t n)
{
	void	*mem;

	if (n == 0)
		return (NULL);
	mem = ft_memalloc(n);
	if (mem == NULL)
		return (NULL);
	ft_memmove(mem, s, n);
	return (mem);
}
