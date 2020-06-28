#include "libft.h"

static int	save_line(t_gl *gl, const int fd, char **mem, char *endl)
{
	size_t		sz;
	size_t		sz1;
	char		*tmp;

	if (endl)
	{
		sz = endl - gl->rs[fd] + 1;
		*mem = ft_memdup(gl->rs[fd], sz);
		tmp = gl->rs[fd];
		sz1 = gl->size[fd] - sz;
		gl->rs[fd] = ft_memdup(endl + 1, sz1);
		ft_memdel((void **)&tmp);
		gl->size[fd] = sz1;
		return (sz);
	}
	else if (gl->size[fd] > 0)
	{
		*mem = ft_memdup(gl->rs[fd], gl->size[fd]);
		sz = gl->size[fd];
		gl->size[fd] = 0;
		ft_memdel((void **)&gl->rs[fd]);
		return (sz);
	}
	return (0);
}

/*
**	Works same as get_next_line, except that ft_getline also
**	supports, in addition to text files, binary files.
**	upon a successful call to it, it returns the number of bytes
**	copied into the buffer mem.	
**	since 'mem' might have null bytes at any location, it is
**	recommended to use `write` syscall to display mem.
*/

int			ft_getline(const int fd, char **mem)
{
	static t_gl	gl;
	void		*e;
	int			r;

	if (fd < 0 || mem == NULL || FD_MAX > 4096)
		return (-1);
	//if (!gl && !(gl = ft_memalloc(sizeof(t_gl))))
		//return (-1);
	r = -1;
	while (!(e = ft_memchr(gl.rs[fd], 10, gl.size[fd])) && 
		(r = read(fd, gl.buf, BUFF_SIZE)) > 0)
	{
		e = gl.rs[fd];	
		gl.rs[fd] = ft_memjoin(gl.rs[fd], gl.buf, gl.size[fd], r);
		gl.size[fd] += r;
		ft_memdel(&e);
		ft_bzero((void *)&gl.buf, BUFF_SIZE);
	}
	return (r < 0 && !e ? -1 : save_line(&gl, fd, mem, e));
}
