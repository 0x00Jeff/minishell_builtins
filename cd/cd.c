#include"utils.h"
#include<stdio.h>

int	cd(char *arg, t_env *env)
{
	t_env	*node;

	if (!arg)
	{
		node = search_in_env(env, "HOME");
		if (!node)
		{
			printf("cd: HOME not set\n");
			return (1);
		}
		else
			change_directory(node->value);
	}
	else
		change_directory(arg);
	return (0);
}
