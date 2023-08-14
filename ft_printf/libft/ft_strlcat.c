/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:13:49 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/10 13:52:03 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (dstsize > 0)
	{
		while (*(dst + i) != '\0')
			i++;
		while (i < dstsize - 1 && *(src + j) != '\0')
		{
			*(dst + i) = *(src + j);
			i++;
			j++;
		}
		*(dst + i) = '\0';
	}
	if (i > dstsize)
		i = dstsize;
	while (*(src + j) != '\0')
	{
		i++;
		j++;
	}
	return (i);
}
