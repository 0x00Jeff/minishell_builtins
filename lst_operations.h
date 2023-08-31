/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:01:05 by afatimi           #+#    #+#             */
/*   Updated: 2023/09/01 00:16:43 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_OPEATIONS
# define LST_OPEATIONS
# include <libft.h>

t_env	*ft_lstnew(char *elem, t_env *prev);
void	ft_lstadd_back(t_env **lst, t_env *new);
int	ft_lstsize(t_env *lst);
void	ft_lstdelone(t_env *lst, void (*del)(void *));
t_env	*ft_lstlast(t_env *lst);
int	ft_lstsize(t_env *lst);
# endif
