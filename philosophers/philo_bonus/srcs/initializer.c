/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:14:03 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/09 18:58:13 by ebraho           ###   ########.fr       */
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
	rules->n_philo_eat = 0;
}

int	set_philo(char **argv, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->n_phil)
	{
		gettimeofday(&rules->philo.last_meal, 0);
		rules->philo.n_eat = 0;
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
	if (!set_philo(argv, rules))
		return (0);
	return (1);
}
