/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:12:52 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/09 18:13:47 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <limits.h>

typedef struct s_philo
{
	pid_t			pid;
	int				id;
	int				n_eat;
	struct timeval	last_meal;
}		t_philo;

typedef struct s_rules
{
	int				n_phil;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_times_each_philo_must_eat;
	int				n_philo_eat;
	int				status;
	sem_t			*fork;
	sem_t			*print;
	t_philo			philo;
}		t_rules;

void			print_taken_fork(long timestamp, int philo_num);
void			print_eating(long timestamp, int philo_num);
void			print_sleeping(long timestamp, int philo_num);
void			print_thinking(long timestamp, int philo_num);
void			print_died(long timestamp, int philo_num);
void			do_nothing(long a, int b);
int				ft_atoi(const char *str);
long			get_timestamp(struct timeval start);
void			check_if_is_dead(t_rules rules, struct timeval *now,
					struct timeval start, void (*f)(long, int));
void			set_params(char **argv, t_rules *rules);
int				set_philo(char **argv, t_rules *rules);
int				initiliaze_rules(char **argv, t_rules *rules);

#endif
