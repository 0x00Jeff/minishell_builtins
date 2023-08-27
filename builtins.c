#include "builtins.h"
#include "builtins_utils.h"
#include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>

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
	if (option && ft_strlen(option + 1) && consists_of(option + 1, 'n'))
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

void	pwd()
{
	// TODO : make this static to handle the edgecase
	// where the mf corrector deletes the current dir
	char *cur_dir;

	cur_dir = getcwd(NULL, 0);
	printf("%s\n", cur_dir);
}
