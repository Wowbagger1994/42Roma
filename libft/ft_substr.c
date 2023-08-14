/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:53:49 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 18:07:02 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*substr;
	unsigned int	i;

	if (s == 0)
		return (0);
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
	substr[i - start] = '\0';
	return (substr);
}
