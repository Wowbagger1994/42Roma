/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_bfs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:25:00 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 12:10:58 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static int	btree_do_bfs(t_btree *root, int lv[2], int *not_first,
		int (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!root)
		return (1);
	if (!btree_do_bfs(root->left,
			(int [2]){lv[0] + 1, lv[1]}, not_first, applyf))
		return (0);
	if (lv[0] == lv[1])
		if (applyf(root->item, lv[1], !(*not_first)++) == 0)
			return (0);
	if (!btree_do_bfs(root->right,
			(int [2]){lv[0] + 1, lv[1]}, not_first, applyf))
		return (0);
	return (1);
}

int	btree_apply_bfs(t_btree *root,
		int (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		i;
	int		first;
	int		depth;

	if (!applyf)
		return (0);
	i = -1;
	depth = btree_depth(root);
	while (++i < depth)
	{
		first = 0;
		if (!btree_do_bfs(root, (int [2]){0, i}, &first, applyf))
			return (0);
	}
	return (1);
}
