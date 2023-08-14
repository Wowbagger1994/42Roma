/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstradd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:06:58 by charmstr          #+#    #+#             */
/*   Updated: 2022/06/14 00:42:00 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strstradd_assist(char **dst, int start, char *src)
{
	char	*new;

	new = ft_substr(*dst, 0, start);
	if (!new)
		return (0);
	new = ft_strjoin_free(new, src, 1);
	if (!new)
		return (0);
	new = ft_strjoin_free(new, *dst + start, 1);
	if (!new)
		return (0);
	ft_free((void **)dst);
	*dst = new;
	return (1);
}

int	ft_strstradd(char **dst, int start, char *src)
{
	int	len;

	if (!dst || !src)
	{
		ft_free((void **)dst);
		return (0);
	}
	len = ft_strlen(*dst);
	if (start > len)
		start = len;
	if (!(*dst))
	{
		*dst = ft_strdup(src);
		if (!(*dst))
			return (0);
	}
	else if (!ft_strstradd_assist(dst, start, src))
	{
		ft_free((void **)dst);
		return (0);
	}
	return (1);
}
