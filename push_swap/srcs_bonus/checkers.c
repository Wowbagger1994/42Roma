/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:26:06 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:49:14 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker.h"

int	is_ordered(int *stack, int dim)
{
	int	i;

	i = 1;
	while (i < dim)
	{
		if (stack[i - 1] > stack[i])
			return (0);
		i++;
	}
	return (1);
}

static int	check_duplicate(int *stack, int dim)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < dim)
	{
		while (++j < dim)
		{
			if (stack[i] == stack[j])
				return (0);
		}
		i++;
		j = i;
	}
	return (1);
}

static void	check_digits(char *str)
{
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if ((*str < '0' || *str > '9'))
			print_error();
		str++;
	}
}

int	parse_string(char *str, int **stack_a, int **stack_b)
{
	int		size;
	char	**split;

	split = ft_split(str, ' ');
	size = 0;
	while (split[size++] != NULL)
		;
	parse_numbers(size - 1, split, stack_a, stack_b);
	return (size - 1);
}

void	parse_numbers(int dim, char **strs, int **stack_a, int **stack_b)
{
	int	i;

	i = 0;
	while (i < dim)
	{
		check_digits(strs[i]);
		ft_atoi(strs[i++]);
	}
	*stack_a = (int *)malloc(sizeof(int) * dim);
	*stack_b = (int *)malloc(sizeof(int) * dim);
	if (!(*stack_b) || !(*stack_a))
		print_error();
	i = 0;
	while (i < dim)
	{
		(*stack_a)[i] = ft_atoi(strs[i]);
		(*stack_b)[i++] = -1;
	}
	if (!check_duplicate(*stack_a, dim))
	{
		free(*stack_a);
		free(*stack_b);
		print_error();
	}
}
