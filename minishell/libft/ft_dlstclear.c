/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:41:07 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/14 11:07:23 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*current;
	t_dlist	*then;

	if (!lst || !*lst)
		return ;
	if (*lst)
	{
		current = (*lst)->next;
		while (current)
		{
			then = current->next;
			ft_dlstdelone(current, del);
			current = then;
		}
	}
	current = *lst;
	while (current)
	{
		then = current->previous;
		ft_dlstdelone(current, del);
		current = then;
	}
	*lst = NULL;
}
