/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_path_parts_root.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta  <pcoletta@student.42roma.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:14:36 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/18 23:29:14 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	match_path_check_valid_star(t_list *wild_cards, int index)
{
	while (wild_cards)
	{
		if (*((int *)(wild_cards->content)) == index)
			return (1);
		wild_cards = wild_cards->next;
	}
	return (0);
}

static int	match_path_part(t_strings strs, t_list *wild_cards, int i, int j)
{
	while (strs.str[i] && strs.ref[j] && (strs.str[i] == strs.ref[j]))
	{
		if (strs.str[i] == '*' && match_path_check_valid_star(wild_cards, i))
			break ;
		i++;
		j++;
	}
	if (ft_isonly(strs.str + i, '*') || (!strs.str[i] && !strs.ref[j]))
		return (1);
	if (!strs.ref[j] || !strs.str[i] || strs.str[i] != '*')
		return (0);
	while (strs.str[i + 1] == '*')
		i++;
	while (strs.ref[j] && strs.ref[j] != strs.str[i + 1])
		j++;
	if (!strs.ref[j])
		return (0);
	return (match_path_part(strs, wild_cards, i, j + 1) \
		|| match_path_part(strs, wild_cards, i + 1, j));
}

int	match_path_part_root(t_list *path_parts, char *ref)
{
	t_list		*wild_cards;
	t_strings	strings;

	strings.str = ((t_path_part *)(path_parts->content))->path_part;
	strings.ref = ref;
	wild_cards = ((t_path_part *)(path_parts->content))->star_index;
	if (!strings.str || !strings.ref)
		return (0);
	if (!(strings.str[0] == '.'))
	{
		if (strings.ref[0] == '.')
			return (0);
	}
	else if (strings.str[0] == '.')
	{
		if (!(strings.ref[0] == '.'))
			return (0);
	}
	if (!wild_cards)
		return (!ft_strcmp(strings.str, strings.ref));
	else
		return (match_path_part(strings, wild_cards, 0, 0));
}
