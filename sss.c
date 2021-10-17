#include "get_next_line.h"


char *ft_settmp(char *tmp)
{
    char *aux;
    char *res;

    if(!ft_strchr(tmp, '\n'))
    {
        res = ft_strdup(tmp, ft_strlen(tmp));
        free(tmp);
        return res;
    }
    res = ft_strdup(tmp, (size_t)(ft_strchr(tmp, '\n') - tmp + 1));
    aux = ft_strdup(ft_strchr(tmp, '\n') + 1,
                ft_strlen(ft_strchr(tmp, '\n') + 1));
    free(tmp);
    tmp = ft_strdup(aux, ft_strlen(aux));
    free(aux);
    return(res);
}

void	ft_setline(char *line, char *mem, char *buffer)
{
	char	*aux;

	if (mem != 0)
	{
		line = ft_strjoin(mem, buffer);
		free(mem);
		mem = 0;
		if (ft_strchr(buffer, '\n') != 0)
			mem = ft_strdup(ft_strchr(buffer, '\n') + 1,
					ft_strlen(ft_strchr(buffer, '\n') + 1));
		return ;
	}
	aux = ft_strdup(line, ft_strlen(line));
	free (line);
	line = ft_strjoin(aux, buffer);
	free (aux);
	if (ft_strchr(buffer, '\n') != 0)
		mem = ft_strdup(ft_strchr(buffer, '\n') + 1,
				ft_strlen(ft_strchr(buffer, '\n') + 1));
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*mem;
	int			read_size;

	line = 0;
	if ((ft_strchr(mem, '\n')) != 0)
		return (ft_settmp(mem));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size == 0 && mem != 0)
		line = ft_settmp(mem);
	while (read_size > 0)
	{
		buffer[read_size] = '\0';
		ft_setline(line, mem, buffer);
		if (!(ft_strchr(buffer, '\n')))
			read_size = read(fd, buffer, BUFFER_SIZE);
		else
			break ;
	}
	free(buffer);
	return (line);
}









