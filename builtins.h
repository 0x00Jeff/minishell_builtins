#ifndef BUILTILNS_H
# define BUILTILNS_H
# include "builtin_utils.h"
# include "lst_operations.h"
# include "utils.h"

extern int g_exit_status;

void	echo(int argc, char **args);
void	cd(char *arg, t_env *env);
void	my_exit(char *arg);
void	export(int argc, char **argv, t_env **env);
void	unset(int argc, char **args, t_env **env);
void	env_(t_env **env);
void	pwd(void);
t_env	*create_env(char **envp);
t_env	*search_in_env(t_env *env, char *key);
char	*pwd_trolling(char *str);
int	check_builtins(int argc, char *command, char **args, t_env **env);
char	**consume_env(t_env *env);
#endif
