/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_dispatcher.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:01:34 by afatimi           #+#    #+#             */
/*   Updated: 2023/09/30 14:01:48 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_DISPATCHER_H
# define BUILTIN_DISPATCHER_H
# include <libft.h>

int		check_builtins(int argc, char *command, char **args, t_env **env);
void	echo(int argc, char **args);
void	pwd(void);
void	cd(char *arg, t_env *env);
#endif
