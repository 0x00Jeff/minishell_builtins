#include "builtin_utils.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h> // TODO : delete this
#include <string.h> // TODO : use libft's instead

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

t_env *create_env(char **envp)
{
	t_env *env;
	t_env *prev;
	t_env *ptr;
	if (!envp || !*envp)
		return (NULL);

	env = NULL;
	prev = NULL;
	while(*envp)
	{
		ptr = ft_lstnew(*envp++, prev);
		prev = ptr;
		// TODO : ask yego how to protect this??
		ft_lstadd_back(&env, ptr);
	}
	ptr -> next = env;
	return (env);
}

void print_env(t_env *env)
{
	t_env *ptr;

	if (!env)
		return;
	ptr = env;
	while(ptr -> next != env)
	{
		printf("%s=%s\n", ptr -> key, ptr -> value);
		ptr = ptr -> next;
	}
	printf("%s=%s\n", ptr -> key, ptr -> value);
}

t_env *search_in_env(t_env *env, char *key)
{
	if (!env)
		return (NULL);
	while(env)
	{
		if (!strcmp(env -> key, key))  // TODO : use the libft version with strcmp
			return (env);
		env = env -> next;
	}
	return (NULL);
}

void del_from_env(t_env *env, char *key)
{
	t_env *node;
	if (!env)
		return ;
	node = search_in_env(env, key);
	node -> prev -> next = node -> next;
	node -> next -> prev = node -> prev;
	ft_lstdelone(node, free);
}
