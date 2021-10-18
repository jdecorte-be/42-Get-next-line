
#include "get_next_line.h"
#include <stdio.h> 

char	*ft_strclr(char *rem, char *buf)
{
	char	*temp;

	temp = ft_strjoin(rem, buf);
	free(rem);
	return (temp);
}

char	*get_line(char *rem)
{
	char	*line;
	int		i;

	i = 0;
	if (!rem[i])
		return (NULL);
	while (rem[i] && rem[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (rem[i] && rem[i] != '\n')
	{
		line[i] = rem[i];
		i++;
	}
	if (rem[i] && rem[i] == '\n')
		line[i++] = '\n';
	return (line);
}
char *read_file(int fd, char *res)
{
    char *buffer;
    int byte_read;

    if(!res)
        res = ft_calloc(1,1);
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    byte_read = 1;
    while (byte_read > 0)
    {
        byte_read = read(fd, buffer, BUFFER_SIZE);
        if (byte_read == -1)
        {
            free(buffer);
            return 0;
        }
        buffer[byte_read] = 0;
        res = ft_strclr(res, buffer);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free(buffer);
    return res;
}

char	*get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return NULL;
    buffer = read_file(fd, buffer);
    if (!buffer)
        return 0;
    line = get_line(buffer);
    buffer = get_left_line(buffer);
    return line;
}

// int main()
// {
//     int fd = open("test.txt", O_RDONLY);
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
//     printf("%s",get_next_line(fd));
// }