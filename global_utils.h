#ifndef GLOBAL_UTILS_H
# define GLOBAL_UTILS_H
extern int g_exit_status;
# include <libft.h>
# include <stdlib.h>
# include "lst_operations.h"
char	*pwd_trolling(char *str);
char	*trim_path(char *pwd);
t_env	*search_in_env(t_env *env, char *key);
t_env	**get_envp_internal(t_env *envp);
t_env	*get_envp(t_env *envp);
char	**consume_env(t_env *env);
char	*get_env_value(char *var);
void	create_env(char **envp);
void log_last_command(char *value);
int	export(int argc, char **argv, t_env **env);
#endif
