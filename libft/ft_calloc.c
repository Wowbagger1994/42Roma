/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:29:49 by ebraho            #+#    #+#             */
/*   Updated: 2023/05/27 00:04:10 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void			*mem;
	unsigned int	i;

	i = 0;
	if (count * size > 16711568)
		return (NULL);
	mem = malloc(count * size);
	if (mem == 0)
		return (0);
	while (i < count * size)
	{
		*((char *)(mem + i)) = 0;
		i++;
	}
	return (mem);
}
