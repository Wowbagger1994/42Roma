/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:16:46 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:31:08 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	next_n(int *stack, int *lis, int lis_lenght, int dim)
{
	int	i;
	int	j;

	i = 0;
	j = dim - 1;
	while ((is_in_lis(lis, lis_lenght, stack[i]) && i != dim))
		i++;
	while ((is_in_lis(lis, lis_lenght, stack[j]) && j != -1))
		j--;
	if (j == -1 && i == stack_len(stack, dim))
		return (-1);
	if (i < dim - j)
		return (i);
	return (j);
}

void	push_to_b(int **a, int **b, int dim)
{
	int	lis_lenght;
	int	i;
	int	n;
	int	*lis;
	int	tmp;

	lis_lenght = get_lis(*a, &lis, dim);
	i = 0;
	while (i < dim)
	{
		n = next_n(*a, lis, lis_lenght, stack_len(*a, dim));
		if (n == -1)
		{
			i++;
			continue ;
		}
		tmp = (*a)[n];
		while ((*a)[0] != tmp)
			is_bt_rt(*a, stack_len(*a, dim), tmp, 1);
		pb(b, a, dim);
		i++;
	}
}

void	check_stack_len(int **a, int **b, int dim)
{
	if (stack_len(*a, dim) == 0)
	{
		pa(a, b, dim);
		pa(a, b, dim);
	}
	else if (stack_len(*a, dim) == 1)
		pa(a, b, dim);
}

int	**copy_stack(int *stack, int dim)
{
	int	**new_stack;
	int	i;

	new_stack = malloc(sizeof(int *));
	if (new_stack == NULL)
		print_error();
	*new_stack = malloc(dim * sizeof(int));
	if (*new_stack == NULL)
		return (NULL);
	i = 0;
	while (i < dim)
	{
		(*new_stack)[i] = stack[i];
		i++;
	}
	return (new_stack);
}

t_stacks	*copy_stacks(t_stacks *stacks)
{
	t_stacks	*new_stack;

	new_stack = malloc(sizeof(t_stacks));
	if (new_stack == NULL)
		return (NULL);
	new_stack->a = copy_stack(*stacks->a, stacks->dim);
	new_stack->b = copy_stack(*stacks->b, stacks->dim);
	new_stack->dim = stacks->dim;
	if (new_stack->a == NULL || new_stack->b == NULL)
	{
		if (new_stack->a != NULL)
			free(new_stack->a);
		if (new_stack->b != NULL)
			free(new_stack->b);
		free(new_stack);
		return (NULL);
	}
	return (new_stack);
}
