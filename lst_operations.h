/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_operations.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:01:05 by afatimi           #+#    #+#             */
/*   Updated: 2023/08/31 22:02:14 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_env	*ft_lstnew(char *elem, t_env *prev);
void	ft_lstadd_back(t_env **lst, t_env *new);
int	ft_lstsize(t_env *lst);
void	ft_lstdelone(t_env *lst, void (*del)(void *));
int	ft_lstsize(t_env *lst);
