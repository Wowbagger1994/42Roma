/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:32:49 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 02:44:16 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_index_valid_kleen_star_to_lst(t_path_part *new, int index)
{
	int		*i;
	t_list	*new_star_index;

	i = malloc(sizeof(int));
	if (!(i))
		return (0);
	*i = index;
	new_star_index = ft_lstnew((void *)i);
	if (!new_star_index)
	{
		free(i);
		return (0);
	}
	ft_lstadd_back(&(new->star_index), new_star_index);
	return (1);
}

static void	path_part_unquoting_assist(char c, char *quoted,
	char *str, int *index)
{
	if (!*quoted)
	{
		*quoted = c;
		ft_strcdel(str, *index);
		(*index)--;
		return ;
	}
	else if (c == quoted[0])
	{
		ft_strcdel(str, *index);
		(*index)--;
		quoted[0] = 0;
	}
}

static void	path_part_unquoting_escape_char(char *str, int *i, char quoted)
{
	if (quoted)
	{
		if (str[*i + 1] && str[*i + 1] == '\\')
		{
			ft_strcdel(str, *i);
			(*i)--;
		}
		return ;
	}
	ft_strcdel(str, *i);
	(*i)--;
}

int	path_part_unquoting(t_path_part *new, char *str)
{
	int	i;
	int	esc_next;

	i = -1;
	esc_next = 0;
	while (str[++i])
	{
		if (!esc_next && str[i] == '\\')
		{
			esc_next = 1;
			path_part_unquoting_escape_char(str, &i, new->quoted);
			continue ;
		}
		if (str[i] == '*' && !esc_next && !new->quoted)
		{
			if (!add_index_valid_kleen_star_to_lst(new, i))
				return (0);
		}
		else if (!esc_next && (str[i] == '\'' || str[i] == '"'))
			path_part_unquoting_assist(str[i], &new->quoted, str, &i);
		esc_next = 0;
	}
	return (1);
}
