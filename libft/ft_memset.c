/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:34:01 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 12:34:03 by ebraho           ###   ########.fr       */
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
