/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:36:07 by afatimi           #+#    #+#             */
/*   Updated: 2023/10/15 13:10:41 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // TODO : GET RID OF THIS AND USE LIBFT's INSTEAD!!
#include <unistd.h>

void	change_directory(char *dir)
{
	char	*path;

	if (!dir)
		return ;
	if (chdir(dir) == -1)
	{
		perror("chdir");
		set_exit_status(1);
		return ;
	}
	path = structure_path(pwd_trolling(NULL), dir);
	if (!opendir(path))
	{
		fprintf(stderr, "SHELL69: cd: ..: No such file or directory\n");
		pwd_trolling(trim_path(join_paths(pwd_trolling(NULL), dir)));
	}
	else
		pwd_trolling(structure_path(pwd_trolling(NULL), dir));
	free(path);
}

char	*contruct_path(char **path)
{
	t_strbuilder	*sb;
	char			*consumed;

	if (!*path)
		return (ft_strdup("/"));
	sb = stringbuilder();
	while (*path)
	{
		sb_append(sb, "/");
		sb_append(sb, *path);
		path++;
	}
	consumed = sb->str;
	free(sb);
	return (consumed);
}

char	*structure_path(char *curr_dir, char *dir)
{
	if (!curr_dir || !dir)
		return (NULL);
	if (!ft_strcmp(dir, "."))
		return (ft_strdup(curr_dir));
	if (*dir == '/')
		return (ft_strdup(dir));
	if (!ft_strnstr(dir, "..", ft_strlen(dir)))
		return (join_paths(curr_dir, dir));
	return (contruct_path(handle_dot_dot_path(join_paths(curr_dir, dir))));
}

int	is_dot_dot(char *slice)
{
	if (!slice)
		return (false);
	return (!ft_strcmp(slice, ".."));
}

void	trim_slices(char **slices)
{
	if (!slices || !*slices)
		return ;
	while (*slices && is_dot_dot(*slices))
	{
		free(*slices);
		*slices = NULL;
		slices++;
	}
	while (*slices && !is_dot_dot(*slices))
		slices++;
	if (*slices)
		shift_slices(slices - 1);
}
