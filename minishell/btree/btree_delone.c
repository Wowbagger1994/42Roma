/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_delone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:59:13 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/21 12:10:58 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_delone(t_btree **node, void (*del)(void *))
{
	if (!*node)
		return ;
	if (del)
		del((*node)->item);
	ft_free((void **)node);
}
