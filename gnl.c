
#include "get_next_line.h"
#include <stdio.h> 
char	*get_next_line(int fd)
{
    static char *buffer;
    char *line;
    int byte_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return NULL;
    byte_read = read(fd, buffer, BUFFER_SIZE);
    buffer[byte_read] = '\0';
    if (byte_read < 0)
    {
        free(buffer);
        return NULL;
    }
    while(byte_read > 0 && ft_strchr(buffer, '\n'))
    {
        buffer[byte_read] = '\0';
        byte_read = read(fd, buffer, BUFFER_SIZE);

        line = ft_strjoin(line, buffer);
    }
    printf("%s", line);
    free(line);
    return line;
}

#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>  
int main()
{
    int fd = open("test.txt", O_RDONLY);
    printf("%s",get_next_line(fd));
}