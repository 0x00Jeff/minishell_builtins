#include "utils.h"
#include<stdlib.h>

void	my_exit(char *arg)
{
	int status;

	status = g_exit_status;
	if (arg)
		status = ft_atoi(arg);
	free(pwd_trolling(NULL));
	exit(status);
}
