
#include "libft.h"

static int	save_line(char **rs, char **line, char *endl)
{
	char	*tmp;

	if (endl)
	{
		tmp = *rs;		
		*line = ft_strsub(*rs, 0, endl - *rs + 1);
		*rs = ft_strdup(endl + 1);
		free(tmp);
		return (1);
	}
	else if (**rs)
	{
		*line = ft_strdup(*rs);
		ft_strdel(rs);
		return (1);
	}
	free(*rs);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*rs[FD_MAX];
	char		*buff;
	int			r;
	char		*e;

	if (fd < 0 || line == NULL || FD_MAX > 4096)
		return (-1);	
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!(rs[fd]) && !(rs[fd] = ft_strnew(0)))
	{
		ft_strdel(&buff);
		return (-1);
	}
	while (!(e = ft_strchr(rs[fd], 10)) && (r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		e = rs[fd];
		rs[fd] = ft_strjoin(rs[fd], buff);
		ft_strdel(&e);
	}
	ft_strdel(&buff);
	return (r < 0 ? -1 : save_line(&rs[fd], line, e));
}
