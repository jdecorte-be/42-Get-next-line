#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
char	        *ft_strdup(const	char *s);
size_t			ft_strlen(const char *s);
char			*ft_alloc(size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strcpy(char *dest, char *src);
char	        *ft_strchr(const char *s, int c);
char			*ft_alloc(size_t size);

# ifndef BUFF_SIZE
#  define BUFF_SIZE 2
# endif

#endif