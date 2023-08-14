/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:08:59 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:31:12 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_bt_rt(int *stack, int dim, int n, int print)
{
	int	i;

	i = 0;
	while (i < dim && stack[i] != n)
		i++;
	if (i < dim / 2)
	{
		if (print)
			ra(&stack, dim);
		return (1);
	}
	if (print)
		rra(&stack, dim);
	return (0);
}

void	exec_moves(int **a, int **b, int dim, t_moves *moves)
{
	while (moves->rr--)
		rr(a, b, dim);
	while (moves->rrr--)
		rrr(a, b, dim);
	while (moves->rb_n--)
		rb(b, dim);
	while (moves->rrb_n--)
		rrb(b, dim);
	while (moves->ra_n--)
		ra(a, dim);
	while (moves->rra_n--)
		rra(a, dim);
}

int	find_max(int *stack, int dim, int n)
{
	int	res;
	int	i;

	i = 0;
	res = n;
	while (i < dim)
	{
		if (stack[i] > n)
			res = stack[i];
		i++;
	}
	if (res != n)
	{
		i = 0;
		while (i < dim)
		{
			if (stack[i] > n && stack[i] < res)
				res = stack[i];
			i++;
		}
	}
	return (res);
}

int	find_min(int *stack, int dim, int n)
{
	int	res;
	int	i;

	i = 0;
	res = n;
	while (i < dim)
	{
		if (stack[i] < n)
			res = stack[i];
		i++;
	}
	if (res != n)
	{
		i = 0;
		while (i < dim)
		{
			if (stack[i] < n && stack[i] > res)
				res = stack[i];
			i++;
		}
	}
	return (res);
}

int	find_max_b(int *stack, int dim)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (i < dim)
	{
		if (stack[i] > stack[res])
			res = i;
		i++;
	}
	return (stack[res]);
}
