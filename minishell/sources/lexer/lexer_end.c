/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 21:24:05 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 03:51:00 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lexer_braces_equal(t_list *tk_head, t_control *control,
	t_token *last)
{
	int		brace[2];

	brace[0] = 0;
	brace[1] = 0;
	while (tk_head && !control->lexer_end.unexpected)
	{
		if (((t_token *)tk_head->content)->id == LBRACE)
			brace[0]++;
		else if (((t_token *)tk_head->content)->id == RBRACE)
			brace[1]++;
		if (brace[0] < brace[1])
			control->lexer_end.unexpected = RBRACE;
		tk_head = tk_head->next;
	}
	if (brace[0] > brace[1])
	{
		control->lexer_end.brace = 1;
		if (last->id != LBRACE)
			control->lexer_end.add_semi = 1;
	}
	else if (brace[0] == brace[1])
		return (1);
	return (0);
}

static int	lexer_signs_near_braces(t_list *tk_head, t_control *control)
{
	t_token		*p_tk;
	t_token		*c_tk;
	t_token		*n_tk;
	int			*sg;

	sg = (int []){LESS, DLESS, GREAT, DGREAT, AND_IF, PIPE, OR_IF, -1};
	p_tk = NULL;
	while (tk_head && !control->lexer_end.unexpected)
	{
		c_tk = (t_token *)tk_head->content;
		if (tk_head->next)
			n_tk = (t_token *)tk_head->next->content;
		else
			n_tk = NULL;
		if (c_tk->id == 5 && p_tk && lexer_tk_notbeside(c_tk, p_tk, sg, 1))
			control->lexer_end.unexpected = LBRACE;
		else if (c_tk->id == 6 && n_tk && lexer_tk_notbeside(c_tk, n_tk, sg, 1))
			control->lexer_end.unexpected = RBRACE;
		p_tk = (t_token *)tk_head->content;
		tk_head = tk_head->next;
	}
	if (control->lexer_end.unexpected)
		return (0);
	else
		return (1);
}

static int	lexer_handle_braces(t_list *tk_head, t_control *control,
	t_token *last)
{
	if (!lexer_signs_near_braces(tk_head, control))
		return (0);
	if (!lexer_braces_equal(tk_head, control, last))
		return (0);
	return (1);
}

int	lexer_id_cmp(t_token *token, int *id)
{
	while (*id != -1)
	{
		if (token->id == *id)
			return (0);
		id++;
	}
	return (-1);
}

int	lexer_end(t_list *token_head, t_control *control)
{
	t_token	*last;

	if (token_head == NULL || (t_token *)(token_head->content) == NULL)
		return (0);
	last = (t_token *)(ft_lstlast(token_head)->content);
	control->lexer_end.unexpected = lexer_forbidden_combo(token_head);
	if (lexer_forbidden_start(token_head) || control->lexer_end.unexpected)
		;
	else if (last->open_quote)
		control->lexer_end.quote = 1;
	else if (last->esc_next)
		control->lexer_end.backslash = 1;
	else if (last->id == AND_IF || last->id == PIPE || last->id == OR_IF)
		control->lexer_end.other = 1;
	else if (last->id == LESS || last->id == DLESS
		|| last->id == GREAT || last->id == DGREAT)
		control->lexer_end.unexpected = last->id;
	else if (ft_lstfind(token_head, (int []){LBRACE, RBRACE, -1},
		lexer_id_cmp) && !lexer_handle_braces(token_head, control, last))
		;
	else
		return (1);
	if (control->lexer_end.unexpected != 0)
		control->exit_status = 258;
	return (0);
}
