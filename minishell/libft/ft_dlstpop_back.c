/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:47:50 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/14 11:07:58 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstpop_back(t_dlist **head, void (*del)(void*))
{
	t_dlist	**current;
	t_dlist	*then;

	if (!head || !del || !*head)
		return ;
	current = head;
	while (*current)
	{
		then = (*current)->next;
		if (!then)
		{
			ft_dlstdelone(*current, del);
			*current = NULL;
			return ;
		}
		current = &(*current)->next;
	}
}
