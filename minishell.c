#include "libft/libft.h"
#include "minishell.h"
#include "builtins.h"
#include<stdio.h>
#include<string.h> // TODO : add clone the libft that has ft_strcmp

int main(int argc, char *argv[], char **envp)
{
	char *command_ptr;
	char command[100];
	char	**args;
	size_t	size;

	(void)argv;
	(void)argc;
	while(1)
	{
		size = 0;
		command_ptr = NULL;
		args  = NULL;
		printf("$ ");fflush(stdout);
		fgets(command, sizeof(command), stdin);
		command[strlen(command) - 1] = 0;

		if (strlen(command) == 1)
			continue;
		args = ft_split(command, ' ');
		command_ptr = args[0];
		args = &args[1];
		while(*args++)
			size++;
		args = ft_split(command, ' ');
		args = &args[1];
		builtins(size, command_ptr, args, envp);
		memset(command, 0, sizeof(command));
	}
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
	else
		ft_putstr_fd("command not a builtin!\n", 2);
//	else if (!strcmp(command, "unset"))
//		unset(argc, args, envp);
//	else if (!strcmp(command, "env"))
//		env(argc, args);
//	else if (!strcmp(command, "exit"))
//		exit(argc, args);
}

