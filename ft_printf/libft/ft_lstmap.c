/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:56:52 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/12 02:25:39 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	t_list	*temp_new;

	temp = lst;
	new = malloc(sizeof(t_list));
	temp_new = new;
	while (temp != 0)
	{
		new->content = malloc(sizeof(temp->content));
		if (new->content == 0)
			return (0);
		new->content = ((*f)(temp->content));
		new->next = malloc(sizeof(t_list));
		if (new->next == 0)
			return (0);
		if (del != 0)
			(*del)(temp->content);
		temp = temp->next;
		if (temp != 0)
			new = new->next;
	}
	free(new->next);
	new->next = 0;
	return (temp_new);
}
