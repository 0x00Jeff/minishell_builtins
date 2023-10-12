/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_dispatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylyoussf <ylyoussf@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:09:31 by afatimi           #+#    #+#             */
/*   Updated: 2023/10/12 18:36:54 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_utils.h"
#include "builtins.h"
#include "global_utils.h"
#include <libft.h>
#include <stdio.h>

int	handle_exit_status(int used, int res)
{
	if (used)
		set_exit_status(res);
	return (used);
}

int	check_builtins(int argc, char *command, char **args)
{
	int	used;
	int	res;

	if (!command)
		return (0);
	res = 0;
	used = 1;
	if (!ft_strcmp(command, "echo"))
		res = echo(argc, args);
	else if (!ft_strcmp(command, "cd"))
		res = cd(*args, get_envp(NULL));
	else if (!ft_strcmp(command, "pwd"))
		res = pwd();
	else if (!ft_strcmp(command, "export"))
		res = export(argc, args, get_envp_internal(NULL));
	else if (!ft_strcmp(command, "unset"))
		res = unset(argc, args, get_envp_internal(NULL));
	else if (!ft_strcmp(command, "exit"))
		my_exit(*args);
	else if (!ft_strcmp(command, "env"))
		res = env_(get_envp_internal(NULL));
	return (handle_exit_status(used, res));
}
