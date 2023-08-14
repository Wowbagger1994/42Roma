/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:49:21 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/14 11:08:05 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstpop_front(t_dlist **head, void (*del)(void*))
{
	t_dlist	*new_head;

	if (!head || !del || !*head)
		return ;
	new_head = (*head)->next;
	ft_dlstdelone(*head, del);
	*head = NULL;
	*head = new_head;
}
