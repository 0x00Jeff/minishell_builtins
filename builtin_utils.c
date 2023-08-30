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
	if (!envp)
		return (NULL);

	env = NULL;
	prev = NULL;
	while(*envp)
	{
		ptr = ft_lstnew(*envp++, prev);
		ft_lstadd_back(&env, ptr);
		prev = ptr;
	}
	return (env);
}

void print_env(t_env *env)
{
	t_env *ptr;

	if (!env)
		return;
	ptr = env;
	while(ptr)
	{
		printf("%s=%s\n", ptr -> key, ptr -> value);
		ptr = ptr -> next;
	}
}

t_env *search_in_env(t_env *env, char *key)
{
	t_env *ptr;
	if (!env || !key)
		return (NULL);
	ptr = env;
	while(ptr)
	{
		if (!strcmp(ptr -> key, key))  // TODO : use the libft version with strcmp
			return (ptr);
		ptr = ptr -> next;
	}
	return (NULL);
}

void del_from_env(t_env **env, char *key)
{
	t_env *node;
	if (!env || !*env)
		return ;
	node = search_in_env(*env, key);
	if (!node)
	{
		ft_putstr_fd("node not found\n", 1);
		return;
	}
	else
		ft_putstr_fd("node found\n", 1);

	printf("list = size = %d\n", ft_lstsize(*env));
	if (node == *env)
		*env = (*env) -> next;
	else if (!node -> next)
		node -> prev -> next = NULL;
	else
	{
		printf("node -> prev = %p\n", node -> prev);
		node -> prev -> next = node -> next;
		node -> next -> prev = node -> prev;
	}

	puts("freeing now .. .");
	ft_lstdelone(node, free);
	printf("list = size = %d\n", ft_lstsize(*env));
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
		return (free_list(pair), printf("export: `%s': not a valid identifier\n", str));
	free_list(pair);
	return (0);
}
