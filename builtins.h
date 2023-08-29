#ifndef BUILTILNS_H
# define BUILTILNS_H
# include "builtin_utils.h"

void echo(int argc, char **args);
void pwd();
void cd(int argc, char *arg);
void my_exit(char *arg);
void export(int argc, char **argv, t_env **env);
void unset(int argc, char **args, t_env *env);
void edit_env_node_value(t_env *node, char *value);
void add_new_node_to_env(t_env **env, char *value);;
#endif
