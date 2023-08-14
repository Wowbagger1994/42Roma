/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isonly_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:00:24 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/14 11:09:43 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isonly_ft(char *str, int (*ft_issmth)(int c), int strict)
{
	int	i;

	i = -1;
	if (!str || !str[0])
	{
		if (strict)
			return (0);
		else
			return (1);
	}
	while (str[++i])
		if (!ft_issmth(str[i]))
			return (0);
	return (1);
}
