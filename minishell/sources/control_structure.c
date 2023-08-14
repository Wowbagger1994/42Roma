/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta <pcoletta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:08:04 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 18:54:12 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_struct(t_control *control, char **environ)
{
	control->env = env_build_linked_list(environ);
	control->term = (t_term *)ft_calloc(sizeof(t_term), 1);
}

static void	init_true_fd(t_control *control)
{
	control->truefd[STDIN_FILENO] = dup(STDIN_FILENO);
	control->truefd[STDOUT_FILENO] = dup(STDOUT_FILENO);
	control->truefd[STDERR_FILENO] = dup(STDERR_FILENO);
}

static void	*terminfo_free_struct(t_term *term)
{
	free(term->line);
	free(term->ps1);
	free(term->ps2);
	free(term);
	return (NULL);
}

int	control_init_struct(t_control *control)
{
	extern char	**environ;

	ft_bzero(control, sizeof(*control));
	control->parent_pid = getpid();
	init_struct(control, environ);
	if (!(control->term) || !(control->env))
		return (0);
	if (!env_shlvl_update(&control->env, control))
		return (0);
	control->cwd = getcwd(NULL, 0);
	if (!(control->cwd))
		return (0);
	init_true_fd(control);
	if (control->truefd[STDIN_FILENO] == -1
		|| control->truefd[STDOUT_FILENO] == -1
		|| control->truefd[STDERR_FILENO] == -1)
		return (0);
	if (tcgetattr(STDIN_FILENO, &control->termios_default) == -1)
		return (0);
	return (1);
}

void	control_free_struct(t_control *control)
{
	terminfo_free_struct(control->term);
	ft_free((void **)&control->cwd);
	ft_lstclear(&control->env, env_del_struct);
	rl_clear_history();
}
