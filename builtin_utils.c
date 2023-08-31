/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:49:12 by afatimi           #+#    #+#             */
/*   Updated: 2023/08/31 01:52:33 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_utils.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // TODO : use libft's instead

int	consists_of(char *line, char c)
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

t_env	*create_env(char **envp)
{
	t_env	*env;
	t_env	*prev;
	t_env	*ptr;

	if (!envp)
		return (NULL);
	env = NULL;
	prev = NULL;
	while (*envp)
	{
		ptr = ft_lstnew(*envp++, prev);
		ft_lstadd_back(&env, ptr);
		prev = ptr;
	}
	return (env);
}

void	print_exports(t_env *env)
{
	t_env	*ptr;

	if (!env)
		return ;
	ptr = env;
	while (ptr)
	{
		if (ptr -> equal_sign)
		{
			if (ptr -> value)
			{
				puts("sign and value good");
				printf("declare -x %s=%s\n", ptr -> key, ptr -> value);
			}
			else
			{
				puts("sign good value bad");
				printf("declare -x %s=\"\"\n", ptr -> key);
			}
		}
		else
		{
			puts("sign bad value bad");
			printf("declare -x %s\n", ptr -> key);
		}
		ptr = ptr->next;
	}
}

void	print_env(t_env *env)
{
	t_env	*ptr;

	if (!env)
		return ;
	ptr = env;
	while (ptr)
	{
		if (ptr -> equal_sign && ptr -> value)
			printf("%s=%s\n", ptr -> key, ptr -> value);
		ptr = ptr->next;
	}
}

t_env	*search_in_env(t_env *env, char *key)
{
	t_env	*ptr;

	if (!env || !key)
		return (NULL);
	ptr = env;
	while (ptr)
	{
		if (!strcmp(ptr->key, key)) // TODO : use the libft version with strcmp
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

void	del_from_env(t_env **env, char *key)
{
	t_env	*node;

	if (!env || !*env)
		return ;
	node = search_in_env(*env, key);
	if (!node)
		return ;
	if (node == *env)
		*env = (*env)->next;
	else if (!node->next)
		node->prev->next = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	ft_lstdelone(node, free);
}

// TODO : this function needs some work
int	validate_var_name(char *str)
{
	if (!str)
		return (1);
	if (ft_isdigit(str[0]))
	{
		printf("export: `%s': not a valid identifier\n", str);
		return (1);
	}
	return (0);
}
