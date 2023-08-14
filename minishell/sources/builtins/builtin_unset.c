/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:07:47 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 22:36:29 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_unset(t_list **env_head, char **argv, t_control *control)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_identifier_valid(argv[i], "unset"))
			unset_in_env_list(env_head, argv[i]);
		else
			control->exit_status = 1;
		i++;
	}
	return (1);
}
