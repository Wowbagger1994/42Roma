/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:59:58 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/11 19:19:31 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		dim_s1;
	int		dim_s2;
	int		i;
	char	*str;

	if (s1 == 0 && s2 == 0)
		return (0);
	i = -1;
	dim_s1 = ft_strlen(s1);
	dim_s2 = ft_strlen(s2);
	str = (char *)malloc(dim_s1 + dim_s2 + 1);
	if (str == 0)
		return (0);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[i - dim_s1] != '\0')
	{
		str[i] = s2[i - dim_s1];
		i++;
	}
	str[i] = '\0';
	return (str);
}
