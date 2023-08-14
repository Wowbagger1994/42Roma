/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:32:25 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/10 16:00:00 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void			*mem;
	unsigned int	i;

	i = 0;
	mem = malloc(count * size);
	if (mem == 0)
		return (0);
	while (i < count)
	{
		*((char *)(mem + i)) = 0;
		i++;
	}
	return (mem);
}
