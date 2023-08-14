/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:06:10 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:06:15 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	strs[k] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		dim;
	int		i;
	int		j;
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
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
