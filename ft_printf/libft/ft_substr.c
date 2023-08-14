/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:00:58 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/11 21:23:57 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*substr;
	unsigned int	i;

	if (start > ft_strlen(s))
		return ((char *)malloc(0));
	i = start;
	substr = (char *)malloc(len + 1);
	if (substr == 0)
		return (0);
	i = start;
	while (s[i] != '\0' && (i - start) < len)
	{
		substr[i - start] = s[i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
