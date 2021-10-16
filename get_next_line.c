/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julrodri <julrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:50:34 by julrodri          #+#    #+#             */
/*   Updated: 2021/10/08 20:01:32 by julrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*o;

// 	fd = open("ola.txt", O_RDONLY);
// 	o = get_next_line(fd);
// 	printf("%s", o);
// 	free(o);
// 	o = get_next_line(fd);
// 	printf("%s", o);
// 	free(o);
// 	o = get_next_line(fd);
// 	printf("%s", o);
// 	free(o);
// 	o = get_next_line(fd);
// 	printf("%s", o);
// 	free(o);
// 	o = get_next_line(fd);
// 	printf("%s", o);
// 	free(o);
// 	o = get_next_line(fd);
// 	printf("%s", o);
// 	free(o);
// }

char	*ft_add_mem(char **mem)
{
	char	*aux;
	char	*line;

	if (!(ft_strchr(*mem, '\n')))
	{
		line = ft_strdup(*mem, ft_strlen(*mem));
		free (*mem);
		*mem = 0;
		return (line);
	}
	line = ft_strdup(*mem, (size_t)(ft_strchr(*mem, '\n') - *mem + 1));
	aux = ft_strdup(ft_strchr(*mem, '\n') + 1,
			ft_strlen(ft_strchr(*mem, '\n') + 1));
	free(*mem);
	*mem = ft_strdup(aux, ft_strlen(aux));
	free(aux);
	return (line);
}

void	ft_add_to_line(char **line, char **mem, char *buffer)
{
	char	*aux;

	if (*mem != 0)
	{
		*line = ft_strjoin(*mem, buffer);
		free(*mem);
		*mem = 0;
		if (ft_strchr(buffer, '\n') != 0)
			*mem = ft_strdup(ft_strchr(buffer, '\n') + 1,
					ft_strlen(ft_strchr(buffer, '\n') + 1));
		return ;
	}
	aux = ft_strdup(*line, ft_strlen(*line));
	free (*line);
	*line = ft_strjoin(aux, buffer);
	free (aux);
	if (ft_strchr(buffer, '\n') != 0)
		*mem = ft_strdup(ft_strchr(buffer, '\n') + 1,
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
		return (ft_add_mem(&mem));
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size == 0 && mem != 0)
		line = ft_add_mem(&mem);
	while (read_size > 0)
	{
		buffer[read_size] = '\0';
		ft_add_to_line(&line, &mem, buffer);
		if (!(ft_strchr(buffer, '\n')))
			read_size = read(fd, buffer, BUFFER_SIZE);
		else
			break ;
	}
	free(buffer);
	return (line);
}
