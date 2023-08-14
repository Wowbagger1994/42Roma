/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:20:00 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/10 01:41:21 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(void *s, int c, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (((unsigned char *)s)[i] == ((unsigned char)c))
			break ;
	}
	if (i < n)
		return (s + i);
	else
		return (0);
}
