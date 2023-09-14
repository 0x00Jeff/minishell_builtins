#include "builtin_utils.h"
#include "builtins.h"
#include <libft.h>
#include <stdio.h>
#include <string.h> // TODO : add clone the libft that has ft_strcmp

int	check_builtins(int argc, char *command, char **args, t_env **env)
{
	if (!command /* || !envp)*/) // TODO : double check this statement
		return (0);
	if (!strcmp(command, "echo")) // TODO : use libft version that has ft_strcmp
		return (echo(argc, args), 1);
	else if (!strcmp(command, "cd"))
		return (cd(*args, *env), 1);
	else if (!strcmp(command, "pwd"))
		return (pwd(*env), 1);
	else if (!strcmp(command, "export"))
		// TODO : this doesn't print like bash command does
		return (export(argc, args, env), 1);
	else if (!strcmp(command, "unset"))
		return (unset(argc, args, env), 1);
	else if (!strcmp(command, "exit"))
		my_exit(*args);
	else if (!strcmp(command, "env"))
		return (env_(env), 1);
	return (0);
}
