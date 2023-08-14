/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:54:51 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 18:18:31 by ebraho           ###   ########.fr       */
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
		str = (char *)malloc(i - start + 2);
	if (str == 0)
		return (0);
	j = 0;
	while (start <= i)
		str[j++] = s1[start++];
	str[j] = '\0';
	return (str);
}
