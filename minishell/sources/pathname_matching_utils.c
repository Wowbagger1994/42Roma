/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname_matching_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:33:26 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/14 01:31:06 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pathname_matched_add_to_list(t_path_exp *tool, char *path)
{
	t_token	*new_token;
	t_list	*new_link;

	if (tool->first_match == 1 && tool->is_filename)
		return (1);
	if (!tool->first_match)
		tool->first_match = 1;
	new_token = lexer_init_token();
	if (!(new_token))
		return (2);
	new_token->str = ft_strdup(path);
	if (!(new_token->str))
	{
		free(new_token);
		return (2);
	}
	new_link = ft_lstnew(new_token);
	if (!(new_link))
	{
		free(new_token->str);
		free(new_token);
		return (2);
	}
	ft_lstadd_back(&tool->matched_paths, new_link);
	return (0);
}

int	pathname_matching_closedir_return(DIR *dir_p, int ret)
{
	closedir(dir_p);
	return (ret);
}
