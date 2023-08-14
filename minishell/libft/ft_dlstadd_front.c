/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:37:18 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/14 11:07:31 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_front(t_dlist **alst, t_dlist *new)
{
	if (!alst || !new)
		return ;
	if (*alst)
	{
		(*alst)->previous = new;
		new->next = *alst;
	}
	*alst = new;
}
