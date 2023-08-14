/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:23:37 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:06:40 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sb(int **b, int dim)
{
	swap(b, dim);
	write (1, "sb\n", 3);
}

void	pb(int **b, int **a, int dim)
{
	push(b, a, dim);
	write(1, "pb\n", 3);
}

void	rb(int **b, int dim)
{
	rotate(b, dim);
	write(1, "rb\n", 3);
}

void	rrb(int **b, int dim)
{
	reverse_rotate(b, dim);
	write(1, "rrb\n", 4);
}
