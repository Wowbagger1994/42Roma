/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isonly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:03:17 by charmstr          #+#    #+#             */
/*   Updated: 2022/06/14 11:08:14 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isonly(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!str[0])
	{
		if (c == '\0')
			return (1);
		else
			return (0);
	}
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}
