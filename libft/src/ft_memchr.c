
#include "libft.h"

void	*ft_memchr(void *mem, int c, size_t n)
{
	unsigned char	*s;
	size_t			i;

	if (mem == NULL || n == 0)
		return (NULL);
	s = (unsigned char *)mem;
	i = 0;
	while (i < n - 1 && s[i] != (unsigned)c)
		i++;
	return (s[i] == (unsigned)c ? &s[i] : 0);
}
