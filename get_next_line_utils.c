#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n--)
	{
		*str++ = 0;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i++ <= (int)ft_strlen(s))
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1 || *s2)
	{
		if (*s1)
			str[i] = *(s1)++;
		else
			str[i] = *(s2)++;
		i++;
	}
	str[i] = '\0';
	return (str);
}