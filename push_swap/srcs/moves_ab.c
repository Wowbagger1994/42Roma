/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:24:50 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:06:27 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(int **a, int **b, int dim)
{
	swap(a, dim);
	swap(b, dim);
	write(1, "ss\n", 3);
}

void	rr(int **a, int **b, int dim)
{
	rotate(a, dim);
	rotate(b, dim);
	write(1, "rr\n", 3);
}

void	rrr(int **a, int **b, int dim)
{
	reverse_rotate(a, dim);
	reverse_rotate(b, dim);
	write(1, "rrr\n", 4);
}
