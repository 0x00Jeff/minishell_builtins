/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:37:21 by afatimi           #+#    #+#             */
/*   Updated: 2023/08/29 21:47:20 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stddef.h>
# include "libft/libft.h"

int	consists_of(char *line , char c);
size_t	count(const char *s, int c);
t_env *create_env(char **envp);
void print_env(t_env *env);
t_env *search_in_env(t_env *env, char *key);
void del_from_env(t_env **env, char *key);
int validate_var_name(char *str);
#endif
