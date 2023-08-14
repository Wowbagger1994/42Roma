/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:05:14 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:31:29 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	search_replace(int *lis, int left, int right, int key)
{
	int	mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

static int	*init_array(int dim, int value)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * dim);
	if (arr == NULL)
		print_error();
	i = 0;
	while (value != -1 && i < dim)
		arr[i++] = value;
	return (arr);
}

static int	calc_lis_length(int dim, int *index, int *lis_count, int *stack)
{
	int	i;
	int	lis_length;

	i = 1;
	lis_length = -1;
	while (i < dim)
	{
		index[i] = search_replace(lis_count, 0, i, stack[i]);
		if (lis_length < index[i])
			lis_length = index[i];
		i++;
	}
	return (lis_length);
}

int	get_lis(int *stack, int **lis, int dim)
{
	int	i;
	int	tmp;
	int	lis_length;
	int	*lis_count;
	int	*index;

	lis_count = init_array(dim, dim);
	index = init_array(dim, 0);
	lis_count[0] = stack[0];
	lis_length = calc_lis_length(dim, index, lis_count, stack);
	(*lis) = init_array(lis_length + 1, -1);
	i = dim - 1;
	tmp = lis_length;
	while (i >= 0)
	{
		if (index[i] == tmp)
			(*lis)[tmp--] = stack[i];
		i--;
	}
	return (lis_length);
}

int	is_in_lis(int *lis, int lis_lenght, int n)
{
	int	i;

	i = 0;
	while (i <= lis_lenght)
	{
		if (n == lis[i])
			return (1);
		i++;
	}
	return (0);
}
