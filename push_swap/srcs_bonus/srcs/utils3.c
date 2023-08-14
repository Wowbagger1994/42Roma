/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:12:19 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:25:37 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	simplify_moves(t_moves *moves)
{
	while (moves->ra_n > 0 && moves->rb_n > 0)
	{
		moves->ra_n--;
		moves->rb_n--;
		moves->rr++;
	}
	while (moves->rra_n > 0 && moves->rrb_n > 0)
	{
		moves->rra_n--;
		moves->rrb_n--;
		moves->rrr++;
	}
}

static void	move_to_first_a(t_stacks *stacks, int n, t_moves *moves)
{
	if (is_bt_rt(*stacks->a, stack_len(*stacks->a, stacks->dim), n, 0))
	{
		rotate(stacks->a, stacks->dim);
		moves->ra_n++;
	}
	else
	{
		reverse_rotate(stacks->a, stacks->dim);
		moves->rra_n++;
	}
}

static void	move_to_first_b(t_stacks *stacks, int n, t_moves *moves)
{
	if (is_bt_rt(*stacks->b, stack_len(*stacks->b, stacks->dim), n, 0))
	{
		rotate(stacks->b, stacks->dim);
		moves->rb_n++;
	}
	else
	{
		reverse_rotate(stacks->b, stacks->dim);
		moves->rrb_n++;
	}
}

void	move_to_first(t_stacks *stacks, int is_a, int n, t_moves *moves)
{
	if (is_a)
		move_to_first_a(stacks, n, moves);
	else
		move_to_first_b(stacks, n, moves);
	simplify_moves(moves);
}

int	sum_moves(t_moves *moves)
{
	return (moves->ra_n + moves->rra_n + moves->rb_n
		+ moves->rrb_n + moves->rrr + moves->rr);
}
