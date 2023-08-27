#include "libft/libft.h"
#include "minishell.h"
#include<stdio.h>
#include<string.h> // TODO : add clone the libft that has ft_strcmp

int main(int argc, char *argv[])
{
	char	**args;

	args = NULL;
	if (argc == 1)
	{
		printf("Usage : %s args\n", argv[0]);
		return (1);
	}
	if (argc >= 3)
		args = &argv[2];
//	printf("command = %s\n", command);
//	printf("option = %s\n", option);
//	printf("arg = %s\n", arg);
	builtins(argc - 2, argv[1], args);
}

void builtins(int argc, char *command, char **args)
{
	if (!command)
		return ;
	if (!strcmp(command, "echo")) // TODO : use libft version that has ft_strcmp
		echo(argc, args);
//	else if (!strcmp(command, "cd"))
//		cd(argc, args);
	else if (!strcmp(command, "pwd"))
		pwd();
//	else if (!strcmp(command, "export"))
//		export(argc, args);
//	else if (!strcmp(command, "unset"))
//		unset(argc, args);
//	else if (!strcmp(command, "env"))
//		env(argc, args);
//	else if (!strcmp(command, "exit"))
//		exit(argc, args);
}

