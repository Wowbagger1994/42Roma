/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:32:55 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:55:43 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_path_part	*init_path_part_link(char *str, char quoted)
{
	t_path_part	*new;

	if (!str)
		return (NULL);
	new = (t_path_part *)malloc(sizeof(t_path_part));
	if (!new)
		return (NULL);
	new->path_part = str;
	new->star_index = NULL;
	new->quoted = quoted;
	return (new);
}

void	delete_path_part_link(void *content)
{
	t_path_part	*elem;

	elem = (t_path_part *)content;
	free(elem->path_part);
	ft_lstclear(&(elem->star_index), free);
	ft_free((void **)&elem);
}

int	add_path_part(char *str, t_list **path_parts, char quoted)
{
	t_path_part	*path_part;
	t_list		*new_link;

	path_part = init_path_part_link(str, quoted);
	if (!(path_part))
	{
		free(str);
		return (0);
	}
	if (!path_part_unquoting(path_part, path_part->path_part))
	{
		delete_path_part_link(path_part);
		return (0);
	}
	new_link = ft_lstnew(path_part);
	if (!(new_link))
	{
		delete_path_part_link(path_part);
		return (0);
	}
	ft_lstadd_back(path_parts, new_link);
	return (1);
}
