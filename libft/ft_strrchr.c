/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:37:34 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 12:37:36 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == (char)c)
			res = (s + i);
		i++;
	}
	if (c == 0)
		return (s + i);
	return (res);
}
