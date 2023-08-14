/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_root.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:35:35 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 02:33:08 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*lexer_error(t_control *control, t_token *new_token, \
	t_list *tokens_head)
{
	control->quit = 1;
	del_token(new_token);
	ft_lstclear(&tokens_head, del_token);
	return (NULL);
}

static t_token	*lexer_build_next_token(const char *input,
		int *j, t_control *control)
{
	t_token		*token;

	token = NULL;
	while (input[*j] == ' ')
		(*j)++;
	if (!input[*j])
		return (token);
	token = lexer_init_token();
	if (!(token) || !lexer_find_token(input, j, token))
	{
		control->quit = 1;
		del_token(token);
		return (NULL);
	}
	return (token);
}

t_list	*lexer_root(char *input, t_control *control)
{
	t_list	*tokens_head;
	t_list	*tokens_elem;
	t_token	*new_token;
	int		i;

	i = 0;
	tokens_head = NULL;
	while (input[i])
	{
		tokens_elem = NULL;
		new_token = lexer_build_next_token(input, &i, control);
		if (new_token)
			tokens_elem = ft_lstnew(new_token);
		if ((!(new_token) && control->quit) || (new_token && !(tokens_elem)))
			return (lexer_error(control, new_token, tokens_head));
		if (tokens_elem)
			ft_lstadd_back(&tokens_head, tokens_elem);
	}
	ft_bzero(&control->lexer_end, sizeof(lexer_end));
	if (!lexer_end(tokens_head, control))
		ft_lstclear(&tokens_head, del_token);
	return (tokens_head);
}

void	del_token(void *token)
{
	if (!token)
		return ;
	if (token_id(token) == CMD)
		free_t_simple_cmd((t_simple_cmd **)(((t_token *)token)->str));
	else if (token_id(token) == LIST)
		ft_lstclear((t_list **)&(((t_token *)token)->str), del_token);
	else
		ft_free((void **)&(((t_token *)token)->str));
	ft_free(&token);
}

t_token	*lexer_init_token(void)
{
	t_token	*token;

	token = (t_token *)ft_memalloc(sizeof(t_token));
	if (!(token))
		return (NULL);
	return (token);
}
