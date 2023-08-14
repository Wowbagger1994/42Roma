/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:18:17 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/10 12:04:51 by Wowbagger        ###   ########.fr       */
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
