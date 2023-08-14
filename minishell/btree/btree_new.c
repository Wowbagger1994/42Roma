/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta <pcoletta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:39:35 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 18:58:14 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_btree	*btree_new(void *item)
{
	t_btree	*new;

	new = ft_calloc(sizeof(t_btree), 1);
	if (!new)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->item = item;
	return (new);
}
