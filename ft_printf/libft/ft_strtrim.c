/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:56:22 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/11 20:33:14 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	int	i;

	i = -1;
	while (set[++i] != '\0')
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		start;

	if (s1 == 0)
		return (0);
	start = 0;
	i = -1;
	while (is_in_set(s1[++i], set))
		start = i + 1;
	i = ft_strlen(s1) - 1;
	while (is_in_set(s1[i], set))
		i--;
	if (start >= i)
		str = (char *)malloc(1);
	else
		str = (char *)malloc(i - start + 1);
	if (str == 0)
		return (0);
	j = 0;
	while (start <= i)
		str[j++] = s1[start++];
	str[++i] = '\0';
	return (str);
}
