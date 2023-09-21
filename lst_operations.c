/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:40:43 by afatimi           #+#    #+#             */
/*   Updated: 2023/09/21 01:19:39 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>
#include <stdio.h> // TODO : delete this
#include "lst_operations.h"
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
			node -> value = ft_strdup(elem + split_index + 1);;
		node -> equal_sign = "";
	}
	node -> prev = prev;
	node -> next = NULL;
	return (node);
}

t_env	*ft_better_lstnew(char *key, char *value, int equal_sign, t_env *prev)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node -> key = key;
	node -> value = value;
	node -> equal_sign = NULL;
	node -> prev = prev;
	node -> next = NULL;
	if (equal_sign)
		node -> equal_sign = "";
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

t_env	*ft_lstlast(t_env *lst)
{
	t_env	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}
