#include"utils.h"

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
		(ft_putstr_fd(args[i++], 1), ft_putstr_fd(" ", 1));
	ft_putstr_fd(args[i++], 1);
	if (new_line)
		ft_putstr_fd("\n", 1);
	return (0);
}