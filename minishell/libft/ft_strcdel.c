/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:14:46 by charmstr          #+#    #+#             */
/*   Updated: 2022/06/14 00:23:01 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcdel(char *str, size_t i)
{
	size_t	len;

	if (!str || !ft_strlen(str))
		return ;
	len = ft_strlen(str);
	if (i >= len)
		return ;
	ft_memmove(str + i, str + i + 1, len - i);
}
