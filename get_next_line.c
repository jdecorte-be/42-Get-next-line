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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

char *get_next_line(int fd)
{
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	char *res = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || !res || BUFFER_SIZE <= 0)
		return NULL;
	int btreaded = read(fd, buffer, BUFFER_SIZE);
	if (btreaded < 0)
		return NULL;
	buffer[btreaded] = '\0';
	if (!buffer[fd])
		buffer[fd] = *ft_strdup("");
	int i = 0;
	while(buffer[i] && buffer[i] != '\n')
	{
		res[i] = buffer[i];
		i++;
	}
	res[i] = '\0';
	printf("%s",res);
	return res;
}
