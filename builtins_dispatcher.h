#ifndef MINISHELL_H
# define MINISHELL_H
# include <libft.h>

int		check_builtins(int argc, char *command, char **args, t_env **env);
void	echo(int argc, char **args);
void	pwd(void);
void	cd(char *arg, t_env *env);
#endif ;
