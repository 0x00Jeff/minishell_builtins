#include "builtin_utils.h"
#include "builtins.h"
#include <libft.h>
#include <stdio.h>
#include <string.h> // TODO : add clone the libft that has ft_strcmp

int g_exit = 0;

int	check_builtins(int argc, char *command, char **args)
{
	int used;
	int res;
	if (!command)
		return (0);
	res = 0;
	used = 0;
	if (!strcmp(command, "echo")) // TODO : use libft version that has ft_strcmp
		(res = echo(argc, args), used = 1);
	else if (!strcmp(command, "cd"))
		(res = cd(*args, get_envp(NULL)), used = 1);
	else if (!strcmp(command, "pwd"))
		(res = pwd(), used = 1);
	else if (!strcmp(command, "export"))
		(res = export(argc, args, get_envp_internal(NULL)), used = 1);
	else if (!strcmp(command, "unset"))
		(res = unset(argc, args, get_envp_internal(NULL)), used = 1);
	else if (!strcmp(command, "exit"))
		my_exit(*args);
	else if (!strcmp(command, "env"))
		(res = env_(get_envp_internal(NULL)), used = 1);
	g_exit_status = res;
	return (used);
}
