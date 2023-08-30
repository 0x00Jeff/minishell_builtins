/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:54:52 by afatimi           #+#    #+#             */
/*   Updated: 2023/08/30 22:18:24 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include"libft.h"

void	ft_lstdelone(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> key);
	del(lst -> value);
	lst -> key = NULL;
	lst -> value = NULL;
	lst -> prev = NULL;
	lst -> next = NULL;
	free(lst);
}
