/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:35:10 by afatimi           #+#    #+#             */
/*   Updated: 2023/10/10 23:08:30 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	print_exports(t_env *env)
{
	t_env	*ptr;

	if (!env)
		return (1);
	ptr = env;
	while (ptr)
	{
		if (ptr->equal_sign)
		{
			if (ptr->value)
				printf("declare -x %s=\"%s\"\n", ptr->key, ptr->value);
			else
				printf("declare -x %s=\"\"\n", ptr->key);
		}
		else
			printf("declare -x %s\n", ptr->key);
		ptr = ptr->next;
	}
	return (0);
}

int	validate_args(int args_num, char **args)
{
	int	i;

	if (!args)
		return (false);
	i = 0;
	while (i < args_num)
	{
		if (validate_var_name(args[i]))
		{
			printf("export: `%s': not a valid identifier\n", args[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_concate(char *str)
{
	char	*concat_sign;
	char	*equal_sign;

	if (!str)
		return (false);
	equal_sign = ft_strchr(str, '=');
	concat_sign = ft_strnstr(str, "+=", ft_strlen(str));
	if (concat_sign && (size_t)concat_sign < (size_t)equal_sign)
		return (true);
	return (false);
}

void	append_to_env(t_env **env, char *key, char *value, int equal_sign)
{
	t_env	*prev;
	t_env	*node;

	if (!env || !value)
		return ;
	prev = NULL;
	if (*env)
		prev = ft_lstlast(*env);
	node = ft_lstnew(key, value, equal_sign, prev);
	ft_lstadd_back(env, node);
}

void	edit_env(t_env *node, char *value, int equal_sign)
{
	if (!node || !value)
		return ;
	free(node->value);
	node->value = value;
	node->equal_sign = equal_sign;
}

int	validate_var_name(char *str)
{
	char	*key;
	size_t	split_index;
	int		res;

	if (!str || is_bad_env_name_start(str[0]))
		return (1);
	split_index = 0;
	if (is_concate(str))
		split_index = (size_t)ft_strchr(str, '+') - (size_t)str;
	else if (ft_strchr(str, '='))
		split_index = (size_t)ft_strchr(str, '=') - (size_t)str;
	if (split_index)
		key = ft_substr(str, 0, split_index);
	else
		key = ft_strdup(str);
	res = ft_is_alphanum_underscore(key + 1);
	free(key);
	return (res);
}

int	is_bad_env_name_start(char c)
{
	return (!ft_isalpha(c) && (c != '_'));
}

void	concate_env(char *key, char *value)
{
	t_env	*node;
	char	*old_value;

	if (!key)
		return ;
	node = search_in_env(get_envp(NULL), key);
	if (node)
	{
		free(key);
		old_value = node->value;
		node->value = ft_strjoin(old_value, value);
		node->equal_sign = 1;
		free(old_value);
		free(value);
	}
	else
	{
		node = ft_lstnew(key, value, 1, ft_lstlast(get_envp(NULL)));
		ft_lstadd_back(get_envp_internal(NULL), node);
	}
}

int	ft_is_alphanum_underscore(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_')
			return (1);
		str++;
	}
	return (0);
}
