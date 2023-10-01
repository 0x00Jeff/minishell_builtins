/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:06:46 by afatimi           #+#    #+#             */
/*   Updated: 2023/10/01 15:48:29 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global_utils.h"
#include <string.h> // TODO : GET RID OF THIS AND USE libft's instead!!
#include "builtins.h" // GET RID OF THIS AFTER WORKING OUT A SOLUTION FOR LOG_LAST_COMMAND

extern int	g_exit_status;

char	*pwd_trolling(char *str)
{
	static char	*pwd;

	if (!str)
		return (pwd);
	free(pwd);
	pwd = trim_path(str);
	return (pwd);
}

char	*trim_path(char *pwd)
{
	size_t	pwd_len;
	size_t	i;
	size_t	fake_i;
	char	*buff;

	pwd_len = ft_strlen(pwd);
	if (ft_strlen(pwd) == 1)
		return (ft_strdup(pwd));
	buff = malloc((pwd_len + 1) * sizeof(char));
	i = 0;
	fake_i = 0;
	while (fake_i < pwd_len)
	{
		if (pwd[fake_i] == '/' && pwd[fake_i + 1] == '/')
		{
			fake_i++;
			continue ;
		}
		buff[i++] = pwd[fake_i++];
	}
	buff[i--] = 0;
	if (ft_strlen(buff) > 1 && buff[i] == '/')
		buff[i] = '\0';
	return (buff);
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

char	**consume_env(t_env *env)
{
	size_t	i;
	char	**ptr;
	size_t	size;
	t_env	*node;
	char	*tmp;

	if (!env)
		return (NULL);
	size = ft_lstsize(env);
	ptr = (char **)malloc((size + 1) * sizeof(char *));
	node = env;
	i = 0;
	while (i < size)
	{
		tmp = ft_strjoin(node->key, "=");
		// TODO: protect this
		ptr[i++] = ft_strjoin(tmp, node->value);
		free(tmp);
		node = node->next;
	}
	ptr[i] = 0;
	return (ptr);
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

void	create_env(char **envp)
{
	t_env	**env;
	t_env	*prev;
	t_env	*ptr;

	if (!envp)
		return ;
	env = get_envp_internal(NULL);
	prev = NULL;
	while (*envp)
	{
		ptr = ft_lstnew(*envp++, prev);
		ft_lstadd_back(env, ptr);
		prev = ptr;
	}
}

void log_last_command(char *value)
{
	char *arr[2];
	if (!value)
		return;

	arr[0] = ft_strjoin("_=", value);
	arr[1] = 0;

	export(1, arr, get_envp_internal(NULL));
	free(arr[0]);
}
