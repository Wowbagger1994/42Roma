/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:26:50 by charmstr          #+#    #+#             */
/*   Updated: 2022/06/13 23:52:56 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strappend(char **str, char c)
{
	char	*char_str;

	char_str = (char [2]){c, '\0'};
	if (!*str)
	{
		*str = ft_strdup(char_str);
		if (!(*str))
			return (0);
	}
	else
	{
		*str = ft_strjoin_free(*str, char_str, 1);
		if (!(*str))
			return (0);
	}
	return (1);
}
