/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:44:21 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/09 18:46:49 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	thread_checkers(t_rules rules, t_state *philo_states,
	struct timeval start, int i)
{
	if (philo_states[i] != rules.philo[i].last_state
		&& (rules.philo[i].n_eat <= -1 || rules.philo[i].n_eat > 0))
	{
		philo_states[i] = rules.philo[i].last_state;
		if (philo_states[i] == thinking)
			print_thinking(get_timestamp(start), rules.philo[i].id);
		if (philo_states[i] == with_a_fork)
			print_taken_fork(get_timestamp(start), rules.philo[i].id);
		else if (philo_states[i] == eating)
		{
			print_taken_fork(get_timestamp(start), rules.philo[i].id);
			print_eating(get_timestamp(start), rules.philo[i].id);
			rules.philo[i].n_eat--;
		}
		else if (philo_states[i] == sleeping)
			print_sleeping(get_timestamp(start), rules.philo[i].id);
		else if (philo_states[i] == dead)
		{
			print_died(get_timestamp(start), rules.philo[i].id);
			return (0);
		}
	}
	return (1);
}

static int	run_checker(t_rules rules, t_state *philo_states,
	struct timeval start)
{
	int	i;

	while (!check_all_have_eaten(&rules))
	{
		i = 0;
		while (i < rules.n_phil)
		{
			if (!thread_checkers(rules, philo_states, start, i))
			{
				free_all(rules, philo_states);
				return (0);
			}
			i++;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_rules			rules;
	t_state			*philo_states;
	int				i;
	struct timeval	start;

	if (argc != 5 && argc != 6)
		return (0);
	i = 0;
	if (!initiliaze_rules(argv, &rules))
		return (0);
	gettimeofday(&start, NULL);
	philo_states = set_states(rules);
	if (!create_threads(rules))
		return (0);
	run_checker(rules, philo_states, start);
}
