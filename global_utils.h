/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:02:00 by afatimi           #+#    #+#             */
/*   Updated: 2023/10/02 14:15:02 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_UTILS_H
# define GLOBAL_UTILS_H
# include "lst_operations.h"
# include <libft.h>
# include <stdlib.h>

extern int	g_exit_status;
char		*pwd_trolling(char *str);
char		*trim_path(char *pwd);
t_env		*search_in_env(t_env *env, char *key);
t_env		**get_envp_internal(t_env *envp);
t_env		*get_envp(t_env *envp);
char		**consume_env(t_env *env);
char		*get_env_value(char *var);
void		create_env(char **envp);
char		*get_key(char *line);
char		*get_value(char *line);
#endif
