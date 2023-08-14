/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:38:29 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 15:49:19 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker.h"

static void	rr(int **stack_a, int **stack_b, int dim)
{
	rotate(stack_a, dim);
	rotate(stack_b, dim);
}

static void	rrr(int **stack_a, int **stack_b, int dim)
{
	reverse_rotate(stack_a, dim);
	reverse_rotate(stack_b, dim);
}

static void	ss(int **stack_a, int **stack_b, int dim)
{
	swap(stack_a, dim);
	swap(stack_b, dim);
}

void	exec_move(char *line, int **stack_a, int **stack_b, int dim)
{
	if (!ft_strncmp("pa\n", line, 3))
		push(stack_a, stack_b, dim);
	else if (!ft_strncmp("pb\n", line, 3))
		push(stack_b, stack_a, dim);
	else if (!ft_strncmp("ra\n", line, 3))
		rotate(stack_a, dim);
	else if (!ft_strncmp("rb\n", line, 3))
		rotate(stack_b, dim);
	else if (!ft_strncmp("rr\n", line, 3))
		rr(stack_a, stack_b, dim);
	else if (!ft_strncmp("rra\n", line, 4))
		reverse_rotate(stack_a, dim);
	else if (!ft_strncmp("rrb\n", line, 4))
		reverse_rotate(stack_b, dim);
	else if (!ft_strncmp("rrr\n", line, 4))
		rrr(stack_a, stack_b, dim);
	else if (!ft_strncmp("sa\n", line, 3))
		swap(stack_a, dim);
	else if (!ft_strncmp("sb\n", line, 3))
		swap(stack_b, dim);
	else if (!ft_strncmp("ss\n", line, 3))
		ss(stack_a, stack_b, dim);
	else
		print_error();
}
