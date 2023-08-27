#include "libft/libft.h"
#include "minishell.h"
#include<stdio.h>
#include<string.h> // TODO : add clone the libft that has ft_strcmp

int main(int argc, char *argv[])
{
	char *arg1, *arg2;
	arg2 = NULL;
	if (argc > 2) // TODO : handle multiple args;
	{
		arg1 = argv[1];
		arg2 = argv[2];
	}
	else if (argc == 1)
		arg1 = argv[1];
	else
		ft_putstr_fd("Usage : command [argument]", 2);

	builtins(arg1, arg2);
}

int builtins(char *command, char *arg)
{
	if (!strcmp(command, "echo"))
		echo(arg);
}

void echo(char *command, arg)
{
	ft_putstr_fd(command, 1);

}
