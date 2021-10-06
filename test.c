#include "get_next_line.c"

int main()
{
    int fd = open("test.txt", O_RDONLY);
    get_next_line(fd);
}