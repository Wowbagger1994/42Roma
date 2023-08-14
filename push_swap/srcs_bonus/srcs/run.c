/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:36:01 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:18:15 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_moves	*calc_moves(t_stacks *stacks, int sel_b, int max_moves)
{
	int		min;
	int		max;
	t_moves	*moves;

	moves = init_moves();
	while ((*stacks->b)[0] != sel_b && sum_moves(moves) < max_moves)
		move_to_first(stacks, 0, sel_b, moves);
	min = find_min((*(stacks->a)),
			stack_len((*(stacks->a)), stacks->dim), (*stacks->b)[0]);
	max = find_max((*(stacks->a)),
			stack_len((*(stacks->a)), stacks->dim), (*stacks->b)[0]);
	if (((*stacks->b)[0] != min && (*stacks->b)[0] != max)
			|| (*stacks->b)[0] == min)
		while ((*(stacks->a))[0] != max && sum_moves(moves) < max_moves)
			move_to_first(stacks, 1, max, moves);
	else if ((*stacks->b)[0] == max)
		while ((*(stacks->a))[stack_len(*stacks->a, stacks->dim) - 1] != min
			&& sum_moves(moves) < max_moves)
			move_to_first(stacks, 1, min, moves);
	return (moves);
}

t_moves	*check_every_b(t_stacks *stacks)
{
	int			i;
	int			b_size;
	t_stacks	*cpy_stacks;
	t_moves		*moves;
	t_moves		*min_moves;

	i = 0;
	moves = NULL;
	min_moves = NULL;
	b_size = stack_len(*(stacks->b), stacks->dim);
	while (i < b_size)
	{
		cpy_stacks = copy_stacks(stacks);
		if (min_moves == NULL)
			moves = calc_moves(cpy_stacks, (*cpy_stacks->b)[i++], INT_MAX);
		else
			moves = calc_moves(cpy_stacks, (*cpy_stacks->b)[i++],
					sum_moves(min_moves));
		if (min_moves == NULL || sum_moves(min_moves) > sum_moves(moves))
			min_moves = moves;
		free(cpy_stacks->a);
		free(cpy_stacks->b);
		free(cpy_stacks);
	}
	return (min_moves);
}

void	run_big_numbers(int **a, int **b, int dim)
{
	int			i;
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		print_error();
	stacks->a = a;
	stacks->b = b;
	stacks->dim = dim;
	push_to_b(stacks->a, stacks->b, dim);
	i = stack_len(*stacks->b, dim);
	check_stack_len(stacks->a, stacks->b, dim);
	while (i-- > 0)
	{
		exec_moves(stacks->a, stacks->b, dim, check_every_b(stacks));
		pa(stacks->a, stacks->b, dim);
	}
	while ((*stacks->a)[0] != 0)
	{
		if (is_bt_rt(*stacks->a, stack_len(*stacks->a, dim), 0, 0))
			ra(stacks->a, dim);
		else
			rra(stacks->a, dim);
	}
}

void	run_of_3(int **a, int dim)
{
	if ((*a)[0] < (*a)[2] && (*a)[1] > (*a)[2])
	{
		sa(a, dim);
		ra(a, dim);
	}
	else if ((*a)[0] > (*a)[1] && (*a)[0] < (*a)[2])
		sa(a, dim);
	else if ((*a)[0] < (*a)[1] && (*a)[0] > (*a)[2])
		rra(a, dim);
	else if ((*a)[0] > (*a)[2] && (*a)[1] < (*a)[2])
		ra(a, dim);
	else if ((*a)[0] > (*a)[1] && (*a)[1] > (*a)[2])
	{
		ra(a, dim);
		sa(a, dim);
	}
}

void	run_of_5(int **a, int **b, int dim)
{
	push_n(a, b, dim, 0);
	push_n(a, b, dim - 1, 4);
	run_of_3(a, dim);
	pa(a, b, dim);
	ra(a, dim);
	pa(a, b, dim);
}
