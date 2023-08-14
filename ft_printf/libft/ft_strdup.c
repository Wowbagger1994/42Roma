/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:55:35 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/10 15:34:06 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*strcpy;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	strcpy = (char *)malloc(i + 1);
	if (strcpy == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		strcpy[i] = s1[i];
		i++;
	}
	strcpy[i] = '\0';
	return (strcpy);
}
