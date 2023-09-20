/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylyoussf <ylyoussf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:49:12 by afatimi           #+#    #+#             */
/*   Updated: 2023/09/20 11:38:53 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_utils.h"
#include "lst_operations.h"
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // TODO : use libft's instead
#include <unistd.h>

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

void	create_env(char **envp)
{
	t_env	**env;
	t_env	*prev;
	t_env	*ptr;

	if (!envp)
		return;
	env = get_envp_internal(NULL);
	prev = NULL;
	while (*envp)
	{
		ptr = ft_lstnew(*envp++, prev);
		ft_lstadd_back(env, ptr);
		prev = ptr;
	}
}

int	print_exports(t_env *env)
{
	t_env	*ptr;

	if (!env)
		return (1);
	ptr = env;
	while (ptr)
	{
		if (ptr -> equal_sign)
		{
			if (ptr -> value)
				printf("declare -x %s=%s\n", ptr -> key, ptr -> value);
			else
				printf("declare -x %s=\"\"\n", ptr -> key);
		}
		else
			printf("declare -x %s\n", ptr -> key);
		ptr = ptr->next;
	}
	return (0);
}

int	print_env(t_env *env)
{
	t_env	*ptr;

	if (!env)
		return (1);
	ptr = env;
	while (ptr)
	{
		if (ptr -> equal_sign && ptr -> value)
			printf("%s=%s\n", ptr -> key, ptr -> value);
		ptr = ptr->next;
	}
	return (0);
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
	char *key;
	size_t split_index;
	int res;

	if (!str || !strcmp(str, "=")) // TODO : use libft verison that has strcmp
		return (1);
	if (ft_isdigit(str[0]))
		return (1);
	if (ft_strchr(str, '='))
	{
		split_index = (size_t)ft_strchr(str, '=') - (size_t)str;
		key = ft_substr(str, 0, split_index);
	}
	else
		key = ft_strdup(str);
	res = ft_is_alphanum_underscore(key + 1);
	free(key);
	return (res);
}

int ft_is_alphanum_underscore(char *str)
{
	if (!str)
		return (1);
	while(*str)
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (1);
		str++;
	}
	return (0);
}

void	append_to_env(t_env **env, char *value)
{
	t_env	*prev;
	t_env	*node;

	if (!env || !value)
		return ;
	prev = NULL;
	if (*env)
		prev = ft_lstlast(*env);
	node = ft_lstnew(value, prev);
	ft_lstadd_back(env, node);
}

void	edit_env(t_env *node, char *value)
{
	if (!node || !value)
		return ;
	free(node->value);
	node -> value = ft_strdup(value);
}

char *pwd_trolling(char *str)
{
	static char *pwd;
	if (!str)
		return (pwd);
	free(pwd);
	pwd = ft_strdup(str);
	return (pwd);
}

char *structure_path(char *curr_dir, char *dir)
{
	char *path;
	char **slice;
	char **slice_ptr;
	char *tmp;
	char *tmp_path;

	if (!curr_dir || !dir)
		return (NULL);
	if (!strcmp(dir, "."))
		return ft_strdup(pwd_trolling(NULL));
	if (*dir == '/')
		return ft_strdup(dir);
	if (!ft_strnstr(dir, "..", ft_strlen(dir)))
	{
		tmp = ft_strjoin(curr_dir, "/");
		path = ft_strjoin(tmp, dir);
		return (free(tmp), path);
	}
	path = ft_strdup("/");
	tmp_path = join_dirs(pwd_trolling(NULL), dir);
	slice = ft_split(tmp_path, '/');
	free(tmp_path);
//	slice_ptr = slice;
//	while(*slice_ptr)
//		printf("%s/", *slice_ptr++);
//	puts("");
	// TODO : protect this split?
	slice_ptr = slice;
	while (*slice_ptr)
	{
//		printf("- slice = %s && slice++ = %s\n", *slice_ptr, *(slice_ptr + 1));
		if (*(slice_ptr + 1) && !strcmp(*(slice_ptr + 1), ".."))
		{
//			printf("skipping over '%s'\n", *slice_ptr);
			slice_ptr+=2;
			continue;
		}
//		printf("===> joining '%s' and '%s'\n", path, *slice_ptr);
		tmp = join_dirs(path, *slice_ptr);
//		printf("===> so far path = '%s'\n", tmp);
		free(path);
		path = tmp;
		slice_ptr++;
	}
	free_list(slice);
	return (path);
}

char *join_dirs(char *dirname, char *basename)
{
	char *tmp;
	char *path;
	if (!dirname || !basename)
		return (NULL);
	if (!strcmp(dirname, "/"))
	{
		if (!strcmp(basename, ".."))
			return (ft_strdup("/"));
		tmp = strdup("/");
	}
	else
		tmp = ft_strjoin(dirname, "/");
	path = ft_strjoin(tmp, basename);
	return (free(tmp), path);
}

char	*get_env_value(char *var)
{
	char	*value;
	t_env	*node;

	node = search_in_env(get_envp(NULL), var + 1);
	free(var);
	if (!node)
		return (ft_strdup(""));
	value = node->value;
	return (ft_strdup(value));
}

void	change_directory(char *dir)
{
	char	*path;

	if (!dir)
		return ;
	if (chdir(dir) == -1)
	{
		perror("chdir");
		return ;
	}
	path = structure_path(pwd_trolling(NULL), dir);
	pwd_trolling(path);
	free(path);
}

t_env	**get_envp_internal(t_env *envp)
{
	static t_env	*env;

	if (envp)
		env = envp;

	return (&env);
}

t_env	*get_envp(t_env *envp)
{
	if (envp)
		get_envp_internal(envp);
	return (*get_envp_internal(NULL));
}
