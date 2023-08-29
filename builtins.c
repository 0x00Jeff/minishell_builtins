#include "builtins.h"
#include "builtin_utils.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void echo(int argc, char **args)
{
	int new_line;
	int i;
	char *option;
	if (!args)
		return (ft_putstr_fd("\n", 1));
	i = 0;
	new_line = 1;
	while (i <= argc - 1)
	{
		option = args[i];
		if (option && ft_strlen(option + 1) && consists_of(option + 1, 'n'))
		{
			new_line = 0;
			i++;
		}
		else
			break;
	}
	while (i < argc - 1)
		ft_putstr_fd(args[i++], 1), ft_putstr_fd(" ", 1);
	if (i <= argc - 1)
		ft_putstr_fd(args[i++], 1);
	if (new_line)
		ft_putstr_fd("\n", 1);
}

void cd(int argc, char *arg)
{
	char *home_dir;
	if (argc && !arg)
		return;
	home_dir = getenv("HOME");
	// TODO : check if MAC's gentev has the extension that allocates the buffer
	// in the heap just like linux
	if (!argc)
	{
		if (!home_dir)
			return (ft_putstr_fd("cd: HOME not set\n", 2));
	//		return (ft_putstr_fd("cd: HOME not set\n", 2), free(home_dir)); ??

		// TODO : test this when u make pwd!!!
		else
		 	if (chdir(home_dir) == -1)
		 		perror("chdir");
	}
	else
	{
		if (arg[0] == '/')
		{
		 	if (chdir(arg) == -1)
		 		perror("chdir");
		}
		else
		{
			;
			// TODO make a path depending on if args is relative or absolute
		}

	}
	// free(cur_dir); ?
	// TODO : change PWD in env
}

void	pwd()
{
	// TODO : make this static to handle the edgecase
	// where the mf corrector deletes the current dir
	char *cur_dir;

	cur_dir = getcwd(NULL, 0);
	printf("%s\n", cur_dir);
}

void export(int argc, char **argv, t_env *env)
{
	// TODO : still have to make append_to_env and del_from_env and search_in_env
	(void)env;
	if (!argc)
		return (print_env(env));
	//printf(search_in_env(env, "HOME2"));
	(void)argv;
}

void my_exit(char *arg)
{
	exit(ft_atoi(arg));
}
