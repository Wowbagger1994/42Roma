/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:31:59 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 12:32:00 by ebraho           ###   ########.fr       */
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
