/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:56:38 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/11 11:09:48 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	int		i;

	new_s = (char *)malloc(ft_strlen(s) + 1);
	if (new_s == 0)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		new_s[i] = (*f)(i, s[i]);
	new_s[i] = '\0';
	return (new_s);
}
