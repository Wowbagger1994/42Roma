/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:35:35 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/09 18:46:45 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	run_child_process(t_rules *rules, struct timeval start)
{
	struct timeval	now;
	struct timeval	is_not_thinking;

	check_if_is_dead(*rules, &now, start, &print_thinking);
	sem_wait(rules->fork);
	check_if_is_dead(*rules, &now, start, &print_taken_fork);
	sem_wait(rules->fork);
	check_if_is_dead(*rules, &now, start, &print_taken_fork);
	gettimeofday(&is_not_thinking, NULL);
	check_if_is_dead(*rules, &now, start, &print_eating);
	while (get_timestamp(is_not_thinking) - get_timestamp(now)
		<= rules->time_to_eat)
		check_if_is_dead(*rules, &now, start, &do_nothing);
	gettimeofday(&rules->philo.last_meal, NULL);
	gettimeofday(&is_not_thinking, NULL);
	sem_post(rules->fork);
	sem_post(rules->fork);
	if (++rules->philo.n_eat == rules->n_of_times_each_philo_must_eat)
		exit(1);
	check_if_is_dead(*rules, &now, start, &print_sleeping);
	while (get_timestamp(is_not_thinking) - get_timestamp(now)
		<= rules->time_to_sleep)
		check_if_is_dead(*rules, &now, start, &do_nothing);
}

static void	run_parent_process(t_rules *rules)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_close(rules->fork);
	sem_close(rules->print);
	while (waitpid(0, &rules->status, 0))
	{
		if (((rules->status >> 8) & 0x000000ff) == 0)
		{
			kill(0, SIGKILL);
			break ;
		}
		if (((rules->status >> 8) & 0x000000ff) == 1)
		{
			if (++rules->n_philo_eat == rules->n_phil)
				break ;
		}
	}
	exit(0);
}

static void	create_child_processes(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_phil)
	{
		rules->philo.pid = fork();
		if (rules->philo.pid < 0)
		{
			sem_unlink("/forks");
			sem_unlink("/print");
			sem_close(rules->fork);
			sem_close(rules->print);
			exit(0);
		}
		else if (rules->philo.pid == 0)
		{
			rules->philo.id = i;
			break ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_rules			rules;
	int				i;
	struct timeval	start;

	if (argc != 5 && argc != 6)
		return (0);
	i = 0;
	if (!initiliaze_rules(argv, &rules))
		return (0);
	gettimeofday(&start, NULL);
	sem_unlink("/forks");
	sem_unlink("/print");
	rules.fork = sem_open("/forks", O_CREAT, 0644, rules.n_phil);
	rules.print = sem_open("/print", O_CREAT, 0644, 1);
	if (rules.fork == SEM_FAILED)
		return (0);
	create_child_processes(&rules);
	if (rules.philo.pid != 0)
		run_parent_process(&rules);
	else
	{
		while (1)
			run_child_process(&rules, start);
		exit(0);
	}
}
