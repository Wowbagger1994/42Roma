/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:26:41 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/10 11:27:02 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned int	i;
	int				res;

	if (n == 0)
		return (0);
	i = 0;
	while (i < (n - 1) && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	res = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
	return (res);
}
