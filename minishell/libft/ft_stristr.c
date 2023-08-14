/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stristr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:40:10 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/13 23:57:14 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stristr(const char *str, char *stack)
{
	int	i;
	int	j;

	if (!str || !stack)
		return (-1);
	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (stack[j])
		{
			if (str[i] == stack[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
