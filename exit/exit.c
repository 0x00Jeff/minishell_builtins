/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <afatimi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:35:51 by afatimi           #+#    #+#             */
/*   Updated: 2023/09/30 14:35:52 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

void	my_exit(char *arg)
{
	int	status;

	status = g_exit_status;
	if (arg)
		status = ft_atoi(arg);
	free(pwd_trolling(NULL));
	exit(status);
}
