/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_depth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:56:35 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 12:10:58 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

int	btree_depth(t_btree *root)
{
	int	max[3];

	if (!root)
		return (0);
	max[0] = btree_depth(root->left);
	max[1] = btree_depth(root->right);
	if (max[0] > max[1])
		max[2] = max[0];
	else
		max[2] = max[1];
	return (max[2] + 1);
}
