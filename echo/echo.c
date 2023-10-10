#include "utils.h"

int	echo(int argc, char **args)
{
	int		new_line;
	int		i;
	char	*opt;

	i = 0;
	new_line = 1;
	while (i <= argc - 1)
	{
		opt = args[i];
		if (opt && ft_strlen(opt + 1) && consist_of(opt + 1, 'n'))
		{
			new_line = 0;
			i++;
		}
		else
			break ;
	}
	while (i < argc - 1)
		print_spaced_arg(args[i++]);
	print_last_arg(args[i], new_line);
	return (0);
}

void	print_spaced_arg(char *arg)
{
	if (!arg)
		return ;
	ft_putstr_fd(arg, 1);
	ft_putstr_fd(" ", 1);
}

void	print_last_arg(char *arg, int new_line)
{
	if (!arg)
		return ;
	ft_putstr_fd(arg, 1);
	if (new_line)
		ft_putstr_fd("\n", 1);
}
