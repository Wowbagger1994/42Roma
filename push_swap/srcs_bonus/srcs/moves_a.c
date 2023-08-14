/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:21:38 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:21:46 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(int **a, int dim)
{
	swap(a, dim);
	write (1, "sa\n", 3);
}

void	pa(int **a, int **b, int dim)
{
	push(a, b, dim);
	write(1, "pa\n", 3);
}

void	ra(int **a, int dim)
{
	rotate(a, dim);
	write(1, "ra\n", 3);
}

void	rra(int **a, int dim)
{
	reverse_rotate(a, dim);
	write(1, "rra\n", 4);
}
