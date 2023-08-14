/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:55:57 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 17:43:20 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	int		i;

	if (s == 0 || f == 0)
		return (0);
	new_s = (char *)malloc(ft_strlen(s) + 1);
	if (new_s == 0)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		new_s[i] = (*f)(i, s[i]);
	new_s[i] = '\0';
	return (new_s);
}
