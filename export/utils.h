#ifndef UTILS_H
# define UTILS_H
# include "../global_utils.h"
# include "../lst_operations.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
int		print_exports(t_env *env);
int		validate_args(int args_num, char **args);
int		is_concate(char *str);
void	concate_env(char *elem);
void	append_to_env(t_env **env, char *value);
void	edit_env(t_env *node, char *value);
int		validate_var_name(char *str);
int		is_bad_env_name_start(char c);
void	concate_env_node(char *key, char *value);
int		ft_is_alphanum_underscore(char *str);
char	*get_key(char *line);
char	*get_value(char *line);
#endif
