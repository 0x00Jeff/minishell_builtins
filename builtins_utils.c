#include "builtins_utils.h"
#include "libft/libft.h"

int	consists_of(char *line , char c)
{
	return (count(line, c) == ft_strlen(line));
}

size_t	count(const char *s, int c)
{
	size_t	res;

	res = 0;
	while (*s)
		res += *s++ == c;
	return (res);
}
