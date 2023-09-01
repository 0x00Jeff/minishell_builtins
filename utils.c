/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:27:45 by afatimi           #+#    #+#             */
/*   Updated: 2023/09/01 01:22:49 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "builtins.h"

char	**consume_env(t_env *env)
{
	size_t	i;
	char	**ptr;
	size_t size;
	t_env	*node;
	if (!env)
		return (NULL);

	size = ft_lstsize(env);
	ptr = (char **)malloc(size + 1);
	node = env;
	i = 0;
	while (i < size)
	{
		ptr[i++] = node -> value;
		node = node -> next;
	}
	ptr[i] = 0;
	return (ptr);
}
