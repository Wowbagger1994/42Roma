/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoletta <pcoletta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:49:51 by pcoletta          #+#    #+#             */
/*   Updated: 2022/01/10 12:49:51 by pcoletta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	i = ft_strlen(s) + 1;
	cc = (char) c;
	while (i--)
	{
		if (s[i] == cc)
			return ((char *) s + i);
	}
	return (NULL);
}
