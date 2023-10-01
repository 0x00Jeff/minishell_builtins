/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:52:58 by afatimi           #+#    #+#             */
/*   Updated: 2023/09/30 14:55:41 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utils.h"

int	export(int argc, char **argv, t_env **env)
{
	int		i;
	char	*ptr;
	char	**tmp;
	t_env	*tmp_node;

	if (!env)
		return (1);
	if (!argc)
		return (print_exports(*env));
	if (validate_args(argc, argv))
		return (1);
	i = 0;
	while (i < argc)
	{
		ptr = argv[i++];
		if (is_concate(ptr))
		{
//			puts("concating");
			concate_env(ptr);
			continue;
		}
		tmp = ft_split(ptr, '=');
		if (!tmp)
			continue ;
		tmp_node = search_in_env(*env, tmp[0]);
		if (!tmp_node)
		{
//			puts("appending to env");
			append_to_env(env, ptr);
		}
		else
		{
//			puts("editing env");
			edit_env(tmp_node, tmp[1]);
		}
		free_list(tmp);
	}
	return (0);
}
