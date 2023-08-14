/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:44:18 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/14 01:31:06 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*to_delete;

	while (*begin_list && !((*cmp)((*begin_list)->content, data_ref)))
	{
		to_delete = *begin_list;
		*begin_list = to_delete->next;
		ft_lstdelone(to_delete, free_fct);
	}
	current = *begin_list;
	while (current != NULL)
	{
		if (current->next && !((*cmp)(current->next->content, data_ref)))
		{
			to_delete = current->next;
			current->next = current->next->next;
			ft_lstdelone(to_delete, free_fct);
		}
		else
			current = current->next;
	}
}
