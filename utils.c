/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:27:45 by afatimi           #+#    #+#             */
/*   Updated: 2023/08/31 22:54:26 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "builtins.h"

char	**consume_env(t_env *env)
{
	size_t	i;
	char	**ptr;
	t_env	*node;
	if (!env)
		return (NULL);

	ptr = (char **)malloc(ft_lstsize(env) + 1);
	node = env;
	i = 0;
	while (i < 0)
	{
		ptr[i] = node -> value;
		node = node -> next;
	}
	ptr[i] = 0;
	return (ptr);
}
