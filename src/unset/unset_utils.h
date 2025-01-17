/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:28:14 by afatimi           #+#    #+#             */
/*   Updated: 2024/02/26 19:44:56 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_UTILS_H
# define UNSET_UTILS_H
# include <global_utils.h>
# include <lst_operations.h>
# include <stdlib.h>

void	del_from_env(t_env **env, char *key);
#endif
