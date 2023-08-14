/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_cmd_assist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:34:33 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:25:08 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_arrow	*init_t_arrow(void)
{
	t_arrow	*arrow;

	arrow = malloc(sizeof(t_arrow));
	if (!arrow)
		return (NULL);
	ft_bzero(arrow, sizeof(t_arrow));
	return (arrow);
}

static int	list_to_cmd_fill_redirections_fields2(t_simple_cmd *cmd, int id, \
		t_list *tokens)
{
	t_arrow	*arrow;
	t_list	*new;
	char	**tmp;

	arrow = init_t_arrow();
	if (!arrow)
		return (0);
	tmp = &((t_token *)tokens->next->content)->str;
	arrow->dest = *tmp;
	*tmp = NULL;
	tmp = &((t_token *)tokens->content)->str;
	arrow->src = *tmp;
	*tmp = NULL;
	arrow->id = id;
	new = ft_lstnew(arrow);
	if (!new)
	{
		free_t_arrow(arrow);
		return (0);
	}
	ft_lstadd_back(&cmd->arrows, new);
	return (1);
}

int	list_to_cmd_fill_redirections_fields(t_simple_cmd *cmd, t_list *tokens)
{
	int	id;

	while (tokens)
	{
		id = tklst_id(tokens);
		if (id == GREAT || id == DGREAT || id == LESS || id == DLESS)
		{
			if (!list_to_cmd_fill_redirections_fields2(cmd, id, tokens))
				return (0);
			tokens = tokens->next;
		}
		tokens = tokens->next;
	}
	return (1);
}

void	free_t_arrow(void *void_arrow)
{
	t_arrow	*arrow;

	arrow = (t_arrow *)void_arrow;
	if (arrow == NULL)
		return ;
	free(arrow->dest);
	free(arrow->src);
	free(arrow);
}
