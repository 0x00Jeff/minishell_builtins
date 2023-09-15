/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 22:50:41 by afatimi           #+#    #+#             */
/*   Updated: 2023/09/15 17:50:20 by afatimi          ###   ########.fr       */
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
	char	*option;

	if (!args)
		return (ft_putstr_fd("\n", 1), 0);
	i = 0;
	new_line = 1;
	while (i <= argc - 1)
	{
		option = args[i];
		if (option && ft_strlen(option + 1) && consists_of(option + 1, 'n'))
		{
			new_line = 0;
			i++;
		}
		else
			break ;
	}
	while (i < argc - 1)
	{
		ft_putstr_fd(args[i++], 1);
		ft_putstr_fd(" ", 1);
	}
	if (i <= argc - 1)
		ft_putstr_fd(args[i++], 1);
	if (new_line)
		ft_putstr_fd("\n", 1);
	return (0);
}

int	cd(char *arg, t_env *env)
{
	t_env	*node;

	//	char **tmp = consume_env(env);
	//	(void)tmp;
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

	//	printf("env = %p -> %p\n", env, *env);
	if (!env)
		return (1);
	if (!argc)
		return (print_exports(*env));
	i = 0;
	while (i < argc)
	{
// TODO : move this outside of the loop -> check the validity of all keys before modifying it
		ptr = argv[i++];
		if (validate_var_name(ptr))
		{
			printf("export: `%s': not a valid identifier\n", ptr);
			return (1);
		}
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
	free(pwd_trolling(NULL));
	exit(ft_atoi(arg));
}

t_env	*get_envp(t_env *envp)
{
	static t_env	*env;

	if (envp)
		env = envp;
	return (env);
}
