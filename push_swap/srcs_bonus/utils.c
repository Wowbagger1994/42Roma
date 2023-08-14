/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:26:52 by ebraho            #+#    #+#             */
/*   Updated: 2022/02/21 14:54:27 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/checker.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	*simplify_stack(int *stack, int dim)
{
	int	i;
	int	j;
	int	n;
	int	*temp;

	i = 0;
	j = 0;
	temp = (int *)malloc(sizeof(int) * dim);
	while (i < dim)
	{
		n = 0;
		while (j < dim)
		{
			if (stack[i] > stack[j++])
				n++;
		}
		temp[i++] = n;
		j = 0;
	}
	return (temp);
}

int	ft_atoi(const char *str)
{
	long	n;
	int		is_neg;

	n = 0;
	is_neg = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg = 1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		n *= 10;
		if (!is_neg)
			n += (*(str++) - '0');
		else
			n -= (*(str++) - '0');
		if (n > 2147483647 || n < -2147483648)
			print_error();
	}
	if (*str != '\0'
		|| (*str == '\0' && (*(str - 1) == '-' || *(str - 1) == '+')))
		print_error();
	return (n);
}

int	stack_len(int *stack, int dim)
{
	int	len;

	len = 0;
	while (stack[len] > -1 && len < dim)
		len++;
	return (len);
}
