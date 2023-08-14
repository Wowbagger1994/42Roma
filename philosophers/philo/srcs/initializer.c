/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 01:48:44 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/09 18:57:13 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	set_params(char **argv, t_rules *rules)
{
	rules->n_phil = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rules->n_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		rules->n_of_times_each_philo_must_eat = -1;
}

int	set_philo(char **argv, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_phil)
	{
		rules->philo[i].rules = rules;
		rules->philo[i].id = i;
		gettimeofday(&rules->philo[i].last_meal, NULL);
		rules->philo[i].last_state = thinking;
		rules->philo[i].n_eat = rules->n_of_times_each_philo_must_eat;
		if (pthread_mutex_init((rules->fork) + i, NULL))
			return (0);
		i++;
	}
	return (1);
}

int	initiliaze_rules(char **argv, t_rules *rules)
{
	int	i;

	set_params(argv, rules);
	if (rules->n_phil < 1)
		return (0);
	rules->fork = malloc(sizeof(pthread_mutex_t) * rules->n_phil);
	rules->philo = malloc(sizeof(t_philo) * rules->n_phil);
	if (rules->fork == NULL || rules->philo == NULL)
		return (0);
	if (!set_philo(argv, rules))
		return (0);
	i = 0;
	while (i < rules->n_phil)
	{
		if (i != 0)
			rules->philo[i].fork_left = rules->fork + i - 1;
		else
			rules->philo[i].fork_left = rules->fork + rules->n_phil - 1;
		if (rules->n_phil > 1)
			rules->philo[i].fork_right = rules->fork + i;
		else
			rules->philo[i].fork_right = 0;
		i++;
	}
	return (1);
}

t_state	*set_states(t_rules rules)
{
	int		i;
	t_state	*philo_states;

	philo_states = malloc(sizeof(t_state) * rules.n_phil);
	if (!philo_states)
		return (0);
	i = 0;
	while (i < rules.n_phil)
		philo_states[i++] = none;
	return (philo_states);
}
