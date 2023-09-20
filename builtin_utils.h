/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:37:21 by afatimi           #+#    #+#             */
/*   Updated: 2023/09/20 19:24:09 by afatimi          ###   ########.fr       */
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
char	*structure_path(char *curr_dir, char *dir);
char	*join_dirs(char *dirname, char *basename);
char	*get_env_value(char *var);
t_env	*get_envp(t_env *envp);
t_env	**get_envp_internal(t_env *envp);
#endif
