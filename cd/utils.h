#ifndef UTILS_H
# define UTILS_H
#include "../global_utils.h"
void	change_directory(char *dir);
char	*structure_path(char *curr_dir, char *dir);
char	*join_dirs(char *dirname, char *basename);
#endif
