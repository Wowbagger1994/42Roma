/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:06:58 by ebraho            #+#    #+#             */
/*   Updated: 2022/06/13 23:59:43 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int to_free)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (to_free & 1)
		ft_free((void **)&s1);
	if (to_free & 2)
		ft_free((void **)&s2);
	return (res);
}
