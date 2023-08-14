/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_root.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:45:40 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:17:14 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*input_reading_and_lexing(t_control *control)
{
	t_list	*token_lst;

	token_lst = NULL;
	read_root(control);
	if (control->quit)
		return (NULL);
	token_lst = lexer_root(control->term->line, control);
	return (token_lst);
}

static void	input_syntax_error(t_control *control, unsigned int unexpected)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	if (unexpected == PIPE)
		ft_putchar_fd('|', 2);
	else if (unexpected == OR_IF)
		ft_putstr_fd("||", 2);
	else if (unexpected == AND_IF)
		ft_putstr_fd("&&", 2);
	else if (unexpected == LBRACE)
		ft_putchar_fd('(', 2);
	else if (unexpected == RBRACE)
		ft_putchar_fd(')', 2);
	else if (unexpected == LESS || unexpected == DLESS || unexpected == GREAT \
			|| unexpected == DGREAT)
		ft_putstr_fd("newline", 2);
	ft_putstr_fd("'\n", 2);
	control->lexer_end.unexpected = 0;
}

static t_list	*input_root_assist_and_prompt(t_control *control)
{
	t_list	*tokens_lst;

	tokens_lst = NULL;
	while (!tokens_lst && !control->quit && !control->lexer_end.unexpected)
	{
		if (control->term->prompt_ps1)
			ft_putstr_fd(control->term->ps1, 2);
		else
			ft_putstr_fd(control->term->ps2, 2);
		tokens_lst = input_reading_and_lexing(control);
		control->term->prompt_ps1 = 0;
		ft_free((void **)&(control->term->line));
	}
	if (control->lexer_end.unexpected)
		input_syntax_error(control, control->lexer_end.unexpected);
	return (tokens_lst);
}

t_list	*input_root(t_control *control)
{
	t_list	*tokens_lst;

	control->term->prompt_ps1 = 1;
	if (!reset_prompts(control->env, control->term))
	{
		control->quit = 1;
		return (NULL);
	}
	tokens_lst = input_root_assist_and_prompt(control);
	return (tokens_lst);
}
