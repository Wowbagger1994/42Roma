/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler_enabler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:44:59 by pcoletta          #+#    #+#             */
/*   Updated: 2022/06/21 02:45:32 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_signalhandler_enable(void)
{
	signal(SIGQUIT, ft_sigquit);
	signal(SIGINT, ft_sigint);
}

void	ft_signalhandler_enable_cmd(void)
{
	signal(SIGQUIT, ft_sigquit_cmd);
	signal(SIGINT, ft_sigint_cmd);
}

void	ft_signalhandler_disable(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}
