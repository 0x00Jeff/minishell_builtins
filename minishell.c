#include "libft/libft.h"
#include "minishell.h"
#include "builtins.h"
#include<stdio.h>
#include<string.h> // TODO : add clone the libft that has ft_strcmp

int main(int argc, char *argv[], char **envp)
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
	builtins(argc - 2, argv[1], args, envp);
}

void builtins(int argc, char *command, char **args, char **envp)
{
	if (!command || !envp) // TODO : double check this statement
		return ;
	if (!strcmp(command, "echo")) // TODO : use libft version that has ft_strcmp
		echo(argc, args);
	else if (!strcmp(command, "cd"))
		cd(argc, *args);
	else if (!strcmp(command, "pwd"))
		pwd();
	else if (!strcmp(command, "export")) // TODO : this doesn't print like bash command does
		export(argc, args, envp);
//	else if (!strcmp(command, "unset"))
//		unset(argc, args, envp);
//	else if (!strcmp(command, "env"))
//		env(argc, args);
//	else if (!strcmp(command, "exit"))
//		exit(argc, args);
}

