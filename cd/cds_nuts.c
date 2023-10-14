/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:36:07 by afatimi           #+#    #+#             */
/*   Updated: 2023/10/14 18:51:30 by afatimi          ###   ########.fr       */
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
	pwd_trolling(path);
	free(path);
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
	print_slices(handle_dot_dot_path(join_paths(curr_dir, dir)));
	return (NULL);
}

char	**handle_dot_dot_path(char *joined_paths)
{
	char *path;
	char **slice;
	char **slice_ptr;
	//char *tmp;
	if (!joined_paths)
		return (NULL);

	path = ft_strdup("/");
	slice = ft_split(joined_paths, '/');
	free(joined_paths);
	// TODO : protect this split?
	slice_ptr = slice;
	while (slice_ptr && *slice_ptr)
	{
	//	print_slices(slice);
		//		printf("- slice = %s && slice++ = %s\n", *slice_ptr, *(slice_ptr + 1));
		if (*(slice_ptr + 1) && !ft_strcmp(*(slice_ptr + 1), ".."))
		{
		//	printf("shifting slices @ %s\n", *slice_ptr);
			if (slice_ptr == slice && ft_strcmp(*slice_ptr, ".."))
				shift_slices(slice_ptr + 1);
			else{
				slice_ptr--;
				shift_slices(slice_ptr + 1);
			}
			print_slices(slice);
			//printf(" 8=====> now pointing @ slice : %s\n", *slice_ptr);
			continue ;
		}
	//	printf(" 8=====> now pointing @ slice : %s\n", *slice_ptr);
		/*
		printf("chunk = %s\n", *slice_ptr);
		//		printf("===> joining '%s' and '%s'\n", path, *slice_ptr);
		tmp = join_dir_chunks(path, *slice_ptr);
		//		printf("===> so far path = '%s'\n", tmp);
		free(path);
		path = tmp;
		*/
		slice_ptr++;
	}
	return (slice);
}

void print_slices(char **slices)
{
	if (!slices)
		return ;
	puts("---------------- new slice listing --------------");
	while(*slices)
		printf("slice = %s\n", *slices++);
	puts("---------------- end slice listing --------------");
}

void shift_slices(char **slices)
{
	if (!slices)
		return ;

	free(*slices);
	*slices = NULL;
	free(*(slices + 1));
	*(slices + 1) = NULL;
	while(*(slices + 2))
	{
		*slices = *(slices + 2);
		slices++;
	}
	*slices = *(slices + 2);
}

int	doesnt_exist(char *path)
{
	DIR	*useless_dir;
	char *tmp_trim;
	int res;
	if (!path)
		return (-1);
	tmp_trim = trim_path(path);
	useless_dir = opendir(tmp_trim);
	printf("useless_dir = %p\n", useless_dir);
	res = !!useless_dir;
	printf("%s -> res : %d\n", path, res);
	if (useless_dir)
	{
		res = 0;
		printf("%s directory exists!\n", tmp_trim);
		closedir(useless_dir);
	}
	else
	{
		res = -1;
		printf("%s directory doesnt exists!\n", tmp_trim);
	}
	printf("returned res = %d\n", res);
	return (res);
}

char	*join_paths(char *dirname, char *basename)
{
	char	*path;
	char	*tmp;

	if (!dirname || !basename)
		return (NULL);
	tmp = ft_strjoin(dirname, "/");
	path = ft_strjoin(tmp, basename);
	return (free(tmp), path);
}

char	*join_dir_chunks(char *dirname, char *basename)
{
	char	*tmp;
	char	*path;

	if (!dirname || !basename)
		return (NULL);
	if (!ft_strcmp(dirname, "/"))
	{
		if (!ft_strcmp(basename, ".."))
			return (ft_strdup("/"));
		tmp = strdup("/");
	}
	else
		tmp = ft_strjoin(dirname, "/");
	path = ft_strjoin(tmp, basename);
	return (free(tmp), path);
}
