#include "libft/libft.h"
#include "minishell.h"
#include "builtins_utils.h"
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
}

void echo(int argc, char **args)
{
	int new_line;
	int i;
	char *option;
	if (!args)
		return (ft_putstr_fd("\n", 1));
	i = 0;
	option = args[i];
	new_line = 1;
	if (option && strlen(option + 1) && consists_of(option + 1, 'n'))
	{
		new_line = 0;
		i++;
	}
	while (i < argc - 1)
	{
		ft_putstr_fd(args[i++], 1);
		ft_putstr_fd(" ", 1);
	}
	ft_putstr_fd(args[i++], 1);
	if (new_line)
		ft_putstr_fd("\n", 1);
}
