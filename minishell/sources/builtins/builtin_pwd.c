/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:02:19 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 22:34:44 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(t_control *control)
{
	control->exit_status = 0;
	ft_putendl_fd(control->cwd, 1);
	return (1);
}
