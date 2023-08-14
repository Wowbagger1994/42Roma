/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:42:20 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 12:10:58 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_add(t_btree **root, t_btree *new, int (*cmpf)(void *, void *))
{
	t_btree	*parent;
	t_btree	*node;
	int		side;

	if (!root || !new)
		return ;
	node = *root;
	if (!node)
		*root = new;
	while (node)
	{
		parent = node;
		side = cmpf(node->item, new->item);
		if (side < 0)
			node = node->right;
		else
			node = node->left;
	}
	if (side >= 0)
		parent->left = new;
	else
		parent->right = new;
}
