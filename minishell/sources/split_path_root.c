/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path_root.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:34:12 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:54:18 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_path_end(char *str, int i, char *quoted)
{
	int	esc_next;

	esc_next = 0;
	while (str[i])
	{
		if (!esc_next & (str[i] == '"' || str[i] == '\''))
			path_set_quoted(str[i], quoted);
		if (!esc_next && str[i] == '\\')
		{
			esc_next = 1;
			i++;
			continue ;
		}
		if (!esc_next && str[i] == '/')
			return (i);
		esc_next = 0;
		i++;
	}
	return (i);
}

static int	split_path(char *str, t_list **paths, int start)
{
	int		end;
	char	*path_part;
	char	quoted;
	char	start_quoted_at_next_path_part;

	quoted = 0;
	while (str[start])
	{
		start_quoted_at_next_path_part = quoted;
		end = find_path_end(str, start, &quoted);
		path_part = ft_substr(str, start, end - start);
		if (!path_part)
			return (0);
		if (!add_path_part(path_part, paths, start_quoted_at_next_path_part))
			return (0);
		if (end == (int)ft_strlen(str))
			return (1);
		start = end + 1;
	}
	path_part = ft_strdup("");
	if (!path_part)
		return (0);
	return (add_path_part(path_part, paths, start_quoted_at_next_path_part));
}

static void	collapse_fwd_slashes(char *str, int esc_next, int i, int k)
{
	while (str[++i])
	{
		if (str[i] == '\\' && esc_next == 0)
		{
			esc_next = 1;
			continue ;
		}
		if (esc_next != 1 && str[i] == '/')
		{
			k = i;
			while (str[++k])
			{
				if (str[k] != '/' && str[k] != '"' && str[k] != '\'')
				{
					i = k - 1;
					break ;
				}
				if (str[k] == '/')
					ft_strcdel(str, k--);
			}
		}
		esc_next = 0;
	}
}

t_list	*split_path_root(char *path_to_dup_and_split)
{
	t_list	*path_parts;
	char	*dup_path;

	path_parts = NULL;
	dup_path = ft_strdup(path_to_dup_and_split);
	if (!(dup_path))
		return (NULL);
	collapse_fwd_slashes(dup_path, 0, -1, 0);
	if (!split_path(dup_path, &path_parts, 0))
	{
		free(dup_path);
		ft_lstclear(&path_parts, delete_path_part_link);
		return (NULL);
	}
	free(dup_path);
	return (path_parts);
}

void	path_set_quoted(char c, char *quoted)
{
	if (!*quoted)
	{
		*quoted = c;
		return ;
	}
	if (c == quoted[0])
		quoted[0] = 0;
}
