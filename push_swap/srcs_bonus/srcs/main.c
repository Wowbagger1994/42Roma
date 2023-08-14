/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 01:14:45 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:45:05 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	run(int size, int **stack_a, int **stack_b)
{
	if (size == 3)
		run_of_3(stack_a, size);
	else if (size == 5)
		run_of_5(stack_a, stack_b, size);
	else
		run_big_numbers(stack_a, stack_b, size);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	*new_stack_a;
	int	size;

	if (argc == 1)
		return (0);
	size = argc - 1;
	if (argc == 2)
		size = parse_string(argv[1], &stack_a, &stack_b);
	else
		parse_numbers(size, argv + 1, &stack_a, &stack_b);
	new_stack_a = simplify_stack(stack_a, size);
	free(stack_a);
	run(size, &new_stack_a, &stack_b);
	free(new_stack_a);
	free(stack_b);
}
