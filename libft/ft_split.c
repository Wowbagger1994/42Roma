/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:55:21 by ebraho            #+#    #+#             */
/*   Updated: 2022/01/10 17:52:42 by ebraho           ###   ########.fr       */
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
	if (s == 0)
		return (0);
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
	strs[k] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		dim;
	int		i;
	int		j;
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (strs == NULL || s == 0)
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
