/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname_expansion_root.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 02:20:52 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/20 16:49:23 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pathname_is_expandable(char *str)
{
	int	quoted;
	int	escaped;
	int	i;

	quoted = 0;
	escaped = 0;
	i = 0;
	while (str[i])
	{
		if (!escaped && str[i] == '\\')
		{
			i++;
			escaped = 1;
			continue ;
		}
		if (!escaped && !quoted && (str[i] == '\"' || str[i] == '\''))
			quoted = str[i];
		else if (!escaped && quoted && str[i] == quoted)
			quoted = 0;
		else if (!escaped && !quoted && str[i] == '*')
			return (1);
		escaped = 0;
		i++;
	}
	return (0);
}

static void	init_path_expansion_struct(t_list *path_parts, \
	t_path_exp *tool, int is_filename)
{
	tool->path_parts = path_parts;
	tool->is_filename = is_filename;
	tool->first_match = 0;
	tool->matched_paths = NULL;
}

static int	pathname_expansion(t_list ***token, int is_filename)
{
	t_list		*path_parts;
	t_path_exp	tool;
	int			res;

	path_parts = split_path_root(((t_token *)((**token)->content))->str);
	if (!(path_parts))
		return (2);
	init_path_expansion_struct(path_parts, &tool, is_filename);
	res = pathname_matching_root(&tool, path_parts);
	if ((res))
	{
		ft_lstclear(&(tool.path_parts), delete_path_part_link);
		ft_lstclear(&(tool.matched_paths), del_token);
		return (res);
	}
	ft_lstclear(&(tool.path_parts), delete_path_part_link);
	word_expand_replace(token, tool.matched_paths);
	ft_lstclear(&(tool.path_parts), delete_path_part_link);
	return (0);
}

int	pathname_expansion_root(t_list **tokens, int is_filename)
{
	int	res;

	while (*tokens)
	{
		if (!pathname_is_expandable(((t_token *)(*tokens)->content)->str))
			quote_removal((t_token *)(*tokens)->content);
		else
		{
			res = pathname_expansion(&tokens, is_filename);
			if (res)
				return (res);
		}
		tokens = &((*tokens)->next);
	}
	return (0);
}
