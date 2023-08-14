/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:36:04 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 12:36:06 by ebraho           ###   ########.fr       */
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
