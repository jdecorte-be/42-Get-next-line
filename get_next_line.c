#include "get_next_line.h"
#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int ft_bufflen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return i;
}


static char		*ft_save(char *lines, size_t *a)
{
	if (ft_strchr(lines, '\n'))
	{
		ft_strcpy(lines, ft_strchr(lines, '\n') + 1);
		return (lines);
	}
	if (ft_bufflen(lines) > 0)
	{
		ft_strcpy(lines, ft_strchr(lines, '\0'));
		*a = 0;
		return (lines);
	}
	return (NULL);
}


int	get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*line_tmp;
	static char		*lines = NULL;
	int				end_buff;
	size_t			a;

	a = 1;
	if (fd < 0  || read(fd, buf, 0) < 0)
		return (-1);
	if (lines == NULL && (lines = ft_alloc(0)) == NULL)
		return (-1);
	while (ft_strchr(lines, '\n') == NULL
		&& (end_buff = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[end_buff] = '\0';
		line_tmp = lines;
		lines = ft_strjoin(line_tmp, buf);
		free(line_tmp);
	}
	*line = ft_substr(lines, 0, ft_bufflen(lines));
	if ((ft_save(lines, &a) != NULL) && a == 1)
		return (1);
	free(lines);
	lines = NULL;
	return (0);
}

