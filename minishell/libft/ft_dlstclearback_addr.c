/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclearback_addr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 09:18:11 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/14 11:07:37 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclearback_addr(t_dlist **lst, void (*del)(void **))
{
	t_dlist	*then;

	if (!lst || !*lst)
		return ;
	while ((*lst)->next)
		(*lst) = (*lst)->next;
	while (*lst)
	{
		then = (*lst)->previous;
		if (del)
			del(&(*lst)->content);
		ft_free((void **)lst);
		(*lst) = then;
	}
}
