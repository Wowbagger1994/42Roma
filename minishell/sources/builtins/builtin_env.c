/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:08:14 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 22:29:06 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	buildin_env(t_list *env, t_control *control)
{
	while (env)
	{
		ft_putstr_fd(((t_env *)env->content)->label, 1);
		ft_putstr_fd("=", 1);
		ft_putendl_fd(((t_env *)env->content)->value, 1);
		env = env->next;
	}
	control->exit_status = 0;
	return (1);
}
