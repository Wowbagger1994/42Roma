/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 02:35:52 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/06 14:55:38 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	eating_state(t_philo *philo, struct timeval now,
	struct timeval *is_not_thinking)
{
	if (get_timestamp(*is_not_thinking) - get_timestamp(now)
		>= philo->rules->time_to_eat)
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		philo->last_state = sleeping;
		gettimeofday(&philo->last_meal, NULL);
		gettimeofday(is_not_thinking, NULL);
	}
}

void	with_a_fork_state(t_philo *philo, struct timeval *is_not_thinking)
{
	if (philo->fork_right && pthread_mutex_lock(philo->fork_right) == 0)
	{
		philo->last_state = eating;
		gettimeofday(is_not_thinking, NULL);
	}
	else
	{
		philo->last_state = thinking;
		pthread_mutex_unlock(philo->fork_left);
	}
}

void	change_state(t_philo *philo, struct timeval now,
	struct timeval *is_not_thinking)
{
	if (get_timestamp(philo->last_meal) - get_timestamp(now)
		> philo->rules->time_to_die)
		philo->last_state = dead;
	else if (philo->last_state == thinking)
	{
		if (pthread_mutex_lock(philo->fork_left) == 0)
			philo->last_state = with_a_fork;
	}
	else if (philo->last_state == with_a_fork)
		with_a_fork_state(philo, is_not_thinking);
	else if (philo->last_state == eating)
		eating_state(philo, now, is_not_thinking);
	else
		if (get_timestamp(*is_not_thinking) - get_timestamp(now)
			>= philo->rules->time_to_sleep)
			philo->last_state = thinking;
}

void	*thread_func(void *arg)
{
	t_philo			*philo;
	struct timeval	now;
	struct timeval	is_not_thinking;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		usleep(100);
		if (philo->n_eat == 0)
		{
			pthread_mutex_unlock(philo->fork_left);
			pthread_mutex_unlock(philo->fork_right);
			break ;
		}
		gettimeofday(&now, NULL);
		change_state(philo, now, &is_not_thinking);
	}
	return (NULL);
}

int	create_threads(t_rules rules)
{
	int	i;

	i = 0;
	while (i < rules.n_phil)
	{
		if (pthread_create(&rules.philo[i].thread_id, NULL,
				thread_func, &rules.philo[i]))
			return (0);
		i++;
	}
	return (1);
}
