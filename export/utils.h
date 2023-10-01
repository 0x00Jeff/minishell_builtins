/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:25:08 by afatimi           #+#    #+#             */
/*   Updated: 2023/10/01 16:52:56 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	concate_env(char *key, char *value);
void	append_to_env(t_env **env, char *value);
void	edit_env(t_env *node, char *value);
int		validate_var_name(char *str);
int		is_bad_env_name_start(char c);
int		ft_is_alphanum_underscore(char *str);
char	*get_key(char *line);
char	*get_value(char *line);
int		handle_concate_case(char *line);
#endif
