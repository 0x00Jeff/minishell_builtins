#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>
# include "libft/libft.h"

int	consists_of(char *line , char c);
size_t	count(const char *s, int c);
t_env *create_env(char **envp);
void print_env(t_env *env);
t_env *search_in_env(t_env *env, char *key);
#endif
