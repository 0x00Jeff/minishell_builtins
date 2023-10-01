/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylyoussf <ylyoussf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:49:12 by afatimi           #+#    #+#             */
/*   Updated: 2023/10/01 15:45:24 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_utils.h"
#include "builtins.h" // delete this after figuring out an actual solution for log_last_command
#include "lst_operations.h"
#include <libft.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // TODO : use libft's instead
#include <unistd.h>

void	set_env_value(char *key, char *value, int equal_sign)
{
	t_env	**env;
	t_env	*node;

	if (!key || !value)
		return ;
	env = get_envp_internal(NULL);
	node = search_in_env(*env, value);
	if (!node)
		better_append_to_env(env, key, value, equal_sign);
	else
		better_edit_env(node, value);
}

void	better_append_to_env(t_env **env, char *key, char *value,
		int equal_sign)
{
	t_env	*prev;
	t_env	*node;

	if (!env || !value)
		return ;
	prev = NULL;
	if (*env)
		prev = ft_lstlast(*env);
	node = ft_better_lstnew(key, value, equal_sign, prev);
	ft_lstadd_back(env, node);
}

void	better_edit_env(t_env *env, char *value)
{
	edit_env(env, value);
}

void	log_last_command(char *value)
{
	char	*arr[2];

	if (!value)
		return ;
	arr[0] = ft_strjoin("_=", value);
	arr[1] = 0;
	export(1, arr, get_envp_internal(NULL));
}
