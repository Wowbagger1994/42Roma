/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:20:26 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/10 01:20:14 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, int len)
{
	int				i;
	unsigned char	uc;

	i = -1;
	uc = (unsigned char)c;
	while (++i < len)
		((unsigned char *)b)[i] = uc;
	return (b);
}
