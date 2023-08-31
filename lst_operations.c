/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:40:43 by afatimi           #+#    #+#             */
/*   Updated: 2023/08/31 22:03:03 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h> // TODO : delete this
#include <stdlib.h>

t_env	*ft_lstnew(char *elem, t_env *prev)
{
	t_env	*node;
	size_t	split_index;

	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	if (!ft_strchr(elem, '='))
	{
		node -> key = ft_strdup(elem);
		node -> value = NULL;
		node -> equal_sign = NULL;
	}
	else
	{
		split_index = (size_t)ft_strchr(elem, '=') - (size_t)elem;
		node -> key = ft_substr(elem, 0, split_index);
		if (elem[split_index + 1] == '\0')
			node -> value = NULL;
		else
			node -> value = ft_strdup(elem + split_index + 1);
		node -> equal_sign = "";
	}
	node -> prev = prev;
	node -> next = NULL;
	return (node);
}

void	ft_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*ptr;

	if (!lst || !new)
		return ;
	ptr = *lst;
	if (ptr)
		ft_lstlast(ptr)->next = new;
	else
		*lst = new;
}

void	ft_lstdelone(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->key);
	del(lst->value);
	lst->key = NULL;
	lst->value = NULL;
	lst->prev = NULL;
	lst->next = NULL;
	free(lst);
}

int	ft_lstsize(t_env *lst)
{
	t_env	*ptr;
	size_t	count;

	ptr = lst;
	if (!ptr)
		return (0);
	count = 1;
	while (ptr->next)
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}
