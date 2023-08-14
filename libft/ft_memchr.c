/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:31:44 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 12:31:46 by ebraho           ###   ########.fr       */
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
