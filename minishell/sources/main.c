/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta <pcoletta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:33:21 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 18:48:46 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	master_loop(t_control *control)
{
	t_list	*tokens_list;
	t_btree	*ast;

	while (!control->quit)
	{
		ft_signalhandler_enable();
		if (!termios_enable_raw_mode(control, &control->termios_default))
			break ;
		tokens_list = input_root(control);
		if (!termios_reset_cooked_mode(control, &control->termios_default))
			break ;
		if (control->quit || control->lexer_end.unexpected)
			continue ;
		ast = parser_root(tokens_list, control);
		if (control->quit)
			break ;
		exe_root(ast, control);
		btree_clear(&ast, del_token);
	}
	return (control->exit_status);
}

int	main(void)
{
	int				exit_status;
	t_control		control;

	if (!control_init_struct(&control)
		|| !(termios_enable_raw_mode(&control, &control.termios_default)))
	{
		if (errno)
			ft_perror(NULL, NULL, strerror(errno));
		else
			ft_perror(NULL, NULL, "Couldn't initialize");
		control_free_struct(&control);
		return (1);
	}
	exit_status = master_loop(&control);
	control_free_struct(&control);
	termios_reset_cooked_mode(&control, &control.termios_default);
	return (exit_status);
}
