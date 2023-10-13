/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:17:57 by afatimi           #+#    #+#             */
/*   Updated: 2023/10/13 14:43:37 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../global_utils.h"

void	change_directory(char *dir);
char	*structure_path(char *curr_dir, char *dir);
char	*joins_paths(char *dirname, char *basename);
char	*join_dir_chunks(char *dirname, char *basename);
#endif
