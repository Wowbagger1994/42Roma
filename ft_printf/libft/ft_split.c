/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wowbagger <enrik.b94@live.it>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:16:13 by Wowbagger         #+#    #+#             */
/*   Updated: 2021/11/11 19:03:55 by Wowbagger        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			count++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static int	word_len(const char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	fill_words(const char *s, char **strs, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				strs[k][j++] = s[i++];
			strs[k][j] = '\0';
			i--;
			k++;
			j = 0;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		dim;
	int		i;
	int		j;
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * count_words(s, c));
	if (strs == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			dim = word_len(s, c, i);
			strs[j] = (char *)malloc(dim + 1);
			if (strs[j++] == NULL)
				return (0);
			i += (dim - 1);
		}
		i++;
	}
	fill_words(s, strs, c);
	return (strs);
}
