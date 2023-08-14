/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:38:29 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 12:38:30 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(char *haystack, const char *needle, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return (haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == *needle)
		{
			while (haystack[i + j] == needle[j] && needle[j] != '\0'
				&& (i + j) < len)
				j++;
		}
		if (needle[j] == '\0')
			return (haystack + i);
		i++;
		j = 0;
	}
	return (0);
}
