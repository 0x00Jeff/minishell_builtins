/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:01:05 by afatimi           #+#    #+#             */
/*   Updated: 2023/08/31 23:35:03 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_OPEATIONS
# define LST_OPEATIONS

t_env	*ft_lstnew(char *elem, t_env *prev);
void	ft_lstadd_back(t_env **lst, t_env *new);
int	ft_lstsize(t_env *lst);
void	ft_lstdelone(t_env *lst, void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_env *lst);
# endif
