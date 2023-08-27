#ifndef MINISHELL_H
# define MINISHELL_H

void builtins(int argc, char *command, char **args);
void echo(int argc, char **args);
void pwd();
# endif
