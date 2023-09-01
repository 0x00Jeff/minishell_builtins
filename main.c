#include<stdio.h>
#include"builtins.h"
#include<string.h>
#include"../libft/libft.h"


int	main(int argc, char *argv[], char **envp)
{
	char	*command_ptr;
	char	command[100];
	char	**args;
	char	**tmp;
	size_t	size;
	t_env	*env;

	(void)argv;
	(void)argc;
	env = create_env(envp);			// TODO : add this
	pwd_trolling(getcwd(NULL, 0)); // TODO : add this
	puts(pwd_trolling(NULL));
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
		check_builtins(size, command_ptr, &args[1], &env);
		memset(command, 0, sizeof(command));
		free_list(args);
	}
}
