#include<stdio.h>
#include<unistd.h>
#include"builtins.h"
#include<string.h>
#include<stdlib.h>
#include<libft.h>

int g_exit_status;


int	main(int argc, char *argv[], char **envp)
{
	char	*command_ptr;
	char	command[100];
	char	**args;
	char	**tmp;
	size_t	size;
	char	*tmp_pwd;

	(void)argv;
	(void)argc;
	create_env(envp);			// TODO : add this
	tmp_pwd = getcwd(NULL, 0);
	pwd_trolling(tmp_pwd); // TODO : add this
	free(tmp_pwd);
	while (1)
	{
		size = 0;
		command_ptr = NULL;
		args = NULL;
		printf("$ ");
		fflush(stdout);
		fgets(command, sizeof(command), stdin);
		command[strlen(command) - 1] = 0;
		if (strlen(command) == 1)
			continue ;
		args = ft_split(command, ' ');
		command_ptr = args[0];
		tmp = &args[1];
		while (*tmp++)
			size++;
		check_builtins(size, command_ptr, &args[1]);
		memset(command, 0, sizeof(command));
		free_list(args);
	}
}
