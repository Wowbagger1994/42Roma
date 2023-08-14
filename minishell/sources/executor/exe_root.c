/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_root.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:52:22 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 03:48:38 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exe_root(t_btree *ast, t_control *control)
{
	t_exe	*exec;
	int		i;
	int		current_id;

	exec = (t_exe []){{AND_IF, exe_and}, {OR_IF, exe_or},
	{PIPE, exe_pipe}, {LIST, exe_cmd}, {-1, exe_semi},
	{SUBSHELL, exe_subshell}, {0, NULL}};
	if (!ast || control->quit)
		return ;
	i = 0;
	current_id = btree_id(ast);
	ft_signalhandler_enable_cmd();
	while (exec[i].fct != NULL && exec[i].id != current_id)
		i++;
	if (exec[i].fct)
		exec[i].fct(ast, control);
}
