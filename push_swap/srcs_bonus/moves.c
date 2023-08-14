/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:21:09 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:50:01 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker.h"

void	swap(int **stack, int dim)
{
	int	temp;
	int	len;

	len = stack_len(*stack, dim);
	if (len == 0 || len == 1)
		return ;
	temp = **stack;
	**stack = *(*(stack) + 1);
	*(*(stack) + 1) = temp;
}

void	push(int **s1, int **s2, int dim)
{
	int	len1;
	int	len2;
	int	i;

	len2 = stack_len(*s2, dim);
	if (len2 == 0)
		return ;
	len1 = stack_len(*s1, dim);
	while (--len1 >= 0)
		(*s1)[len1 + 1] = (*s1)[len1];
	(*s1)[0] = (*s2)[0];
	i = -1;
	while (++i < len2 - 1)
		*(*(s2) + i) = *(*(s2) + i + 1);
	*(*(s2) + i) = -1;
}

void	rotate(int	**stack, int dim)
{
	int	temp;
	int	len;
	int	i;

	len = stack_len(*stack, dim);
	if (len == 0 || len == 1)
		return ;
	temp = **stack;
	i = 0;
	while (i++ < len - 1)
		*(*(stack) + i - 1) = *(*(stack) + i);
	*(*(stack) + i - 1) = temp;
}

void	reverse_rotate(int **stack, int dim)
{
	int	temp;
	int	len;

	len = stack_len(*stack, dim);
	if (len == 0 || len == 1)
		return ;
	temp = (*stack)[--len];
	while (--len >= 0)
		(*stack)[len + 1] = (*stack)[len];
	**stack = temp;
}

void	push_n(int **a, int **b, int dim, int n)
{
	int	i;

	i = 0;
	while ((*a)[i] != n)
		i++;
	if (i <= dim / 2 && i != 0)
	{
		while (--i >= 0)
			rotate(a, dim);
	}
	else if (i > dim / 2 && i != 0)
	{
		while (i++ < dim)
			reverse_rotate(a, dim);
	}
	push(b, a, dim);
}
