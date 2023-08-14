/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_expand_root_v2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:25:06 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/20 17:42:05 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	word_expand_stage1(t_list **tokens, t_control *control)
{
	int	res;
	int	is_filename;

	if (!tild_expansion_root(control->env, \
		&((t_token *)(*tokens)->content)->str))
		return (2);
	is_filename = ((t_token *)((*tokens)->content))->is_filename;
	res = parameter_expansion_root(*tokens, control, is_filename);
	if (res)
		return (res);
	skim_empty_tokens(tokens);
	if (!*tokens)
		return (3);
	if (is_filename && ft_strlen(((t_token *)(*tokens)->content)->str) == 0)
		return (1);
	res = pathname_expansion_root(tokens, is_filename);
	return (res);
}

static t_list	*dup_token(const t_token *token)
{
	t_list	*new_list;
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!(new_token))
		return (NULL);
	ft_memcpy(new_token, token, sizeof(t_token));
	new_token->str = ft_strdup(token->str);
	if (!(new_token->str))
	{
		del_token(new_token);
		return (NULL);
	}
	new_list = ft_lstnew(new_token);
	if (!(new_list))
	{
		del_token(new_token);
		return (NULL);
	}
	return (new_list);
}

static int	word_expand_and_replace(t_list ***tokens, t_control *control)
{
	t_list	*expanded_word;
	int		res;
	t_list	*del_me;

	expanded_word = dup_token((**tokens)->content);
	if (!(expanded_word))
		return (2);
	res = word_expand_stage1(&expanded_word, control);
	if (res)
	{
		if (res == 1)
			ft_ambiguous_redirect(((t_token *)(**tokens)->content)->str, 2);
		if (res < 3)
			ft_lstclear(&expanded_word, del_token);
		if (res == 3)
		{
			del_me = **tokens;
			**tokens = (**tokens)->next;
			del_token(del_me->content);
			ft_free((void **)&del_me);
		}
		return (res);
	}
	word_expand_replace(tokens, expanded_word);
	return (0);
}

int	word_expand_root(t_list **tokens, t_control *control)
{
	int	id;
	int	res;

	while (*tokens)
	{
		id = tklst_id(*tokens);
		if (id == GREAT || id == DGREAT || id == LESS)
		{
			tokens = &(*tokens)->next;
			((t_token *)(*tokens)->content)->is_filename = 1;
		}
		if (id == DLESS)
			tokens = &(*tokens)->next->next;
		if (!(*tokens))
			break ;
		res = word_expand_and_replace(&tokens, control);
		if (res == 1 || res == 2)
			return (res);
		if (res == 3)
			;
		else
			tokens = &(*tokens)->next;
	}
	return (0);
}

void	word_expand_replace(t_list ***tokens, t_list *expanded)
{
	t_list	*last;
	t_list	*del_me;

	if (expanded)
	{
		last = ft_lstlast(expanded);
		last->next = (**tokens)->next;
		del_me = **tokens;
		**tokens = expanded;
		*tokens = &last;
		del_token(del_me->content);
		free(del_me);
	}
}
