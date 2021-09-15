#include "get_next_line.h"

size_t	ft_bufflen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
    if(fd < 0)
        return 0;
}

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int     main()
{

}