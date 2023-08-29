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
	while(ptr && ptr -> next != env)
	{
		printf("%s=%s\n", ptr -> key, ptr -> value);
		ptr = ptr -> next;
	}
	if (ptr)
		printf("%s=%s\n", ptr -> key, ptr -> value);
}

t_env *search_in_env(t_env *env, char *key)
{
	t_env *ptr;
	if (!env)
		return (NULL);
	ptr = env;
	while(ptr -> next != env)
	{
		if (!strcmp(ptr -> key, key))  // TODO : use the libft version with strcmp
			return (ptr);
		ptr = ptr -> next;
	}
	if (!strcmp(ptr -> key, key))  // TODO : use the libft version with strcmp
		return (ptr);
	return (NULL);
}

void del_from_env(t_env *env, char *key)
{
	t_env *node;
	if (!env)
		return ;
	node = search_in_env(env, key);
	if (!node)
		return;
	node -> prev -> next = node -> next;
	node -> next -> prev = node -> prev;
	ft_lstdelone(node, free);
}

int validate_var_name(char *str)
{
	char **pair;

	if (!str)
		return (1);
	if (!strrchr(str, '='))
		return (1);
	pair = ft_split(str, '=');
	if (!pair)
		return (1);
	if (!pair[0] || !pair[1])
	{
		free_list(pair);
		return (1); //  TODO : might do return !!!free_list(pair)
	}
	if (ft_isdigit(str[0]))
		return printf("export: `%s': not a valid identifier\n", str);
	return (0);
}
