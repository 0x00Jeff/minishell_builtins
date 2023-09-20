/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:50:41 by afatimi           #+#    #+#             */
/*   Updated: 2023/09/21 00:15:04 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_utils.h"
#include "builtins.h"
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	echo(int argc, char **args)
{
	int		new_line;
	int		i;
	char	*opt;

	i = 0;
	new_line = 1;
	while (i <= argc - 1)
	{
		opt = args[i];
		if (opt && ft_strlen(opt + 1) && consist_of(opt + 1, 'n'))
		{
			new_line = 0;
			i++;
		}
		else
			break ;
	}
	while (i < argc - 1)
		(ft_putstr_fd(args[i++], 1), ft_putstr_fd(" ", 1));
	ft_putstr_fd(args[i++], 1);
	if (new_line)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	cd(char *arg, t_env *env)
{
	t_env	*node;

	if (!arg)
	{
		node = search_in_env(env, "HOME");
		if (!node)
		{
			printf("cd: HOME not set\n");
			return (1);
		}
		else
			change_directory(node->value);
	}
	else
		change_directory(arg);
	return (0);
}

int	pwd(void)
{
	// TODO : might replace with ft_putstr_fd
	printf("%s\n", pwd_trolling(NULL));
	return (0);
}

int	env_(t_env **env)
{
	return (print_env(*env));
}

int	export(int argc, char **argv, t_env **env)
{
	int		i;
	char	*ptr;
	char	**tmp;
	t_env	*tmp_node;

	if (!env)
		return (1);
	if (!argc)
		return (print_exports(*env));
	i = 0;
	while (i < argc)
	{
		ptr = argv[i++];
		if (validate_var_name(ptr))
		{
			printf("export: `%s': not a valid identifier\n", ptr);
			return (1);
		}
	}
	i = 0;
	while (i < argc)
	{
		ptr = argv[i++];
		tmp = ft_split(ptr, '=');
		if (!tmp)
			continue ;
		tmp_node = search_in_env(*env, tmp[0]);
		if (!tmp_node)
		{
//			puts("appending to env");
			append_to_env(env, ptr);
		}
		else
		{
//			puts("editing env");
			edit_env(tmp_node, tmp[1]);
		}
		free_list(tmp);
	}
	return (0);
}

int	unset(int argc, char **args, t_env **env)
{
	char	*ptr;
	int		i;

	if (!args || !env)
		return (1);
	i = 0;
	while (i < argc)
	{
		ptr = args[i++];
		del_from_env(env, ptr);
	}
	return (0);
}

void	my_exit(char *arg)
{
	int status;

	status = g_exit_status;
	if (arg)
		status = ft_atoi(arg);
	free(pwd_trolling(NULL));
	exit(status);
}
