#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

#endif