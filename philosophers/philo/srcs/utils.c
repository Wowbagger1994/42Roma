/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:57:14 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/06 14:55:51 by ebraho           ###   ########.fr       */
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

long	get_timestamp(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec - start.tv_sec) * 1000
		+ (end.tv_usec - start.tv_usec) / 1000);
}

int	check_all_have_eaten(t_rules *rules)
{
	int	i;

	if (rules->n_of_times_each_philo_must_eat == -1)
		return (0);
	i = 0;
	while (i < rules->n_phil)
	{
		if (rules->philo[i].n_eat > 0)
			return (0);
		i++;
	}
	return (1);
}

void	free_all(t_rules rules, t_state *philo_states)
{
	int	i;

	i = 0;
	while (i < rules.n_phil)
		pthread_mutex_destroy(&rules.fork[i++]);
	free(rules.philo);
	free(rules.fork);
	free(philo_states);
}
