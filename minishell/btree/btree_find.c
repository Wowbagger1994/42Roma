/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:24:47 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 12:10:58 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	*btree_find(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	void	*res;

	if (!root)
		return (NULL);
	res = btree_find(root->left, data_ref, cmpf);
	if (res)
		return (res);
	if (!cmpf(root->item, data_ref))
		return (root->item);
	res = btree_find(root->right, data_ref, cmpf);
	if (res)
		return (res);
	return (NULL);
}
