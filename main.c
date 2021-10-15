#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"

int main()
{
	int fd = open("foo.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}