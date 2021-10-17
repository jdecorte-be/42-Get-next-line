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

void	free_ptr(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s_buff = NULL;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!s_buff)
		s_buff = ft_strdup("");
	if (read_file(fd, &buffer, &s_buff, &line) == 0 && *line == '\0')
	{
		free_ptr(line);
		return (NULL);
	}
	return (line);
}

int	read_file(int fd, char **buffer, char **s_buff, char **line)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (!ft_strchr(*s_buff, '\n') && bytes_read)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes_read] = '\0';
		temp = *s_buff;
		*s_buff = ft_strjoin(*s_buff, *buffer);
		free_ptr(temp);
	}
	free_ptr(*buffer);
	get_line(line, s_buff);
	return (bytes_read);
}

char	*get_line(char **line, char **s_buff)
{
	char	*buff_temp;
	int		buff_nl;

	buff_nl = 0;
	buff_temp = *s_buff;
	while ((*s_buff)[buff_nl] != '\n' && (*s_buff)[buff_nl] != '\0')
		buff_nl++;
	if (ft_strchr(*s_buff, '\n'))
	{
		*line = ft_substr(*s_buff, 0, buff_nl + 1);
		*s_buff = ft_strdup(*s_buff + buff_nl + 1);
	}
	else
	{
		*line = ft_strdup(buff_temp);
		*s_buff = NULL;
	}
	free_ptr(buff_temp);
	return (*line);
}
