/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:46:37 by haaghaja          #+#    #+#             */
/*   Updated: 2025/02/16 16:24:22 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			*str;
	static ssize_t	bytes_read;
	static ssize_t	buffer_offset;
	static char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_calloc(1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (get_line(&str, buffer, &buffer_offset))
			break ;
		if (!str)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (exit_gnl(str));
		buffer_offset = 0;
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
	}
	return (str);
}
