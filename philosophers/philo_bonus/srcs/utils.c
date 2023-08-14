/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:57:14 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/08 22:13:25 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_atoi(const char *str)
{
	int	n;
	int	is_neg;

	n = 0;
	is_neg = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		is_neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		n *= 10;
		if (!is_neg)
			n += (*str - '0');
		else
			n -= (*str - '0');
		str++;
	}
	return (n);
}

void	check_if_is_dead(t_rules rules, struct timeval *now,
	struct timeval start, void (*f)(long, int))
{
	gettimeofday(now, NULL);
	if (get_timestamp(rules.philo.last_meal) - get_timestamp(*now)
		> rules.time_to_die)
	{
		sem_wait(rules.print);
		print_died(get_timestamp(start), rules.philo.id);
		exit(0);
	}
	sem_wait(rules.print);
	f(get_timestamp(start), rules.philo.id);
	sem_post(rules.print);
}

long	get_timestamp(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec - start.tv_sec) * 1000
		+ (end.tv_usec - start.tv_usec) / 1000);
}

void	do_nothing(long a, int b)
{
	if (a < b)
		return ;
	return ;
}
