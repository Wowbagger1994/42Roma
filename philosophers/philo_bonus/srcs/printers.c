/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:53:54 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/08 17:46:55 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_taken_fork(long timestamp, int philo_num)
{
	printf("%ld %i has take a fork\n", timestamp, philo_num);
}

void	print_eating(long timestamp, int philo_num)
{
	printf("%ld %i is eating\n", timestamp, philo_num);
}

void	print_sleeping(long timestamp, int philo_num)
{
	printf("%ld %i is sleeping\n", timestamp, philo_num);
}

void	print_thinking(long timestamp, int philo_num)
{
	printf("%ld %i is thinking\n", timestamp, philo_num);
}

void	print_died(long timestamp, int philo_num)
{
	printf("%ld %i died\n", timestamp, philo_num);
}
