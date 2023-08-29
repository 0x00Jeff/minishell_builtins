#ifndef BUILTILNS_H
# define BUILTILNS_H
# include "builtin_utils.h"

void echo(int argc, char **args);
void pwd();
void cd(int argc, char *arg);
void my_exit(char *arg);
void export(int argc, char **argv, t_env *env);
#endif
