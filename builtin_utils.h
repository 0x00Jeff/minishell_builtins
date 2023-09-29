/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:37:21 by afatimi           #+#    #+#             */
/*   Updated: 2023/09/29 11:48:23 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_UTILS_H
# define BUILTIN_UTILS_H
# include <libft.h>
# include <stddef.h>

int		consist_of(char *line, char c);
size_t	count(const char *s, int c);
void	create_env(char **envp);
t_env	*search_in_env(t_env *env, char *key);
void	del_from_env(t_env **env, char *key);
int		validate_var_name(char *str);
int		print_exports(t_env *env);
int		print_env(t_env *env);
int		ft_is_alphanum_underscore(char *str);
char	*pwd_trolling(char *str);
void	change_directory(char *dir);
char	*trim_path(char *pwd);
void	append_to_env(t_env **env, char *value);
void	edit_env(t_env *node, char *value);
char	*get_env_value(char *var);
t_env	*get_envp(t_env *envp);
t_env	**get_envp_internal(t_env *envp);
void	concate_env(char *elem);
int		is_concate(char *str);
void	concate_env_node(char *key, char *value);
int validate_args(int args_num, char **args);
int is_bad_env_name_start(char c);
void log_last_command(char *value);
#endif
