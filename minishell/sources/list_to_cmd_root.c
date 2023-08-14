/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_cmd_root.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:33:05 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/20 20:53:48 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	list_to_cmd_fill_argv_array(t_simple_cmd *cmd, t_list *tokens)
{
	int		size;
	int		index;
	t_list	*copy;

	copy = tokens;
	size = 0;
	index = 0;
	while (copy)
	{
		copy = copy->next;
		size++;
	}
	cmd->argv = malloc(sizeof(char *) * (size + 1));
	if (!(cmd->argv))
		return (0);
	cmd->argv[size] = NULL;
	while (tokens)
	{
		cmd->argv[index] = ((t_token *)tokens->content)->str;
		((t_token *)tokens->content)->str = NULL;
		tokens = tokens->next;
		index++;
	}
	return (1);
}

static t_list	*list_to_cmd_skim_redirections(t_list **tokens)
{
	t_list	*redirections;
	t_list	*couple;

	redirections = NULL;
	while (*tokens)
	{
		if (tklst_id(*tokens) == GREAT || tklst_id(*tokens) == DGREAT \
					|| tklst_id(*tokens) == LESS || tklst_id(*tokens) == DLESS)
		{
			couple = *tokens;
			*tokens = (*tokens)->next->next;
			couple->next->next = NULL;
			ft_lstadd_back(&redirections, couple);
		}
		else
			tokens = &(*tokens)->next;
	}
	return (redirections);
}

static t_simple_cmd	*init_t_simple_cmd(void)
{
	t_simple_cmd	*cmd;

	cmd = malloc(sizeof(t_simple_cmd));
	if (!(cmd))
		return (NULL);
	ft_bzero(cmd, sizeof(t_simple_cmd));
	return (cmd);
}

int	list_to_cmd_root(t_token *token_node)
{
	t_simple_cmd	*cmd;
	t_list			*tokens_list;
	t_list			*redirections;

	tokens_list = (t_list *)(token_node->str);
	cmd = init_t_simple_cmd();
	if (!cmd)
		return (0);
	redirections = list_to_cmd_skim_redirections(&tokens_list);
	if (!list_to_cmd_fill_argv_array(cmd, tokens_list)
		|| !list_to_cmd_fill_redirections_fields(cmd, redirections))
	{
		ft_lstclear(&redirections, del_token);
		free_t_simple_cmd(cmd);
		return (0);
	}
	ft_lstclear(&redirections, del_token);
	ft_lstclear(&tokens_list, del_token);
	token_node->str = (char *)cmd;
	token_node->id = CMD;
	return (1);
}

void	free_t_simple_cmd(void *void_cmd)
{
	t_simple_cmd	*cmd;

	cmd = (t_simple_cmd *)void_cmd;
	ft_array_free(cmd->argv, ft_array_len(cmd->argv));
	ft_lstclear(&cmd->arrows, free_t_arrow);
	free(cmd);
}
