/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebraho <ebraho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:12:37 by ebraho            #+#    #+#             */
/*   Updated: 2022/03/09 18:12:38 by ebraho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef enum e_state {
	none,
	thinking,
	with_a_fork,
	eating,
	sleeping,
	dead
}	t_state;

typedef struct s_rules	t_rules;

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	struct timeval	last_meal;
	int				n_eat;
	t_state			last_state;
	t_rules			*rules;
}		t_philo;

typedef struct s_rules
{
	int				n_phil;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_times_each_philo_must_eat;
	pthread_mutex_t	*fork;
	t_philo			*philo;
}		t_rules;

void	print_taken_fork(long timestamp, int philo_num);
void	print_eating(long timestamp, int philo_num);
void	print_sleeping(long timestamp, int philo_num);
void	print_thinking(long timestamp, int philo_num);
void	print_died(long timestamp, int philo_num);
int		ft_atoi(const char *str);
long	get_timestamp(struct timeval start);
int		check_all_have_eaten(t_rules *rules);
void	free_all(t_rules rules, t_state *philo_states);
void	set_params(char **argv, t_rules *rules);
int		set_philo(char **argv, t_rules *rules);
int		initiliaze_rules(char **argv, t_rules *rules);
t_state	*set_states(t_rules rules);
int		create_threads(t_rules rules);
void	*thread_func(void *arg);
void	change_state(t_philo *philo, struct timeval now,
			struct timeval *is_not_thinking);
void	with_a_fork_state(t_philo *philo, struct timeval *is_not_thinking);
void	eating_state(t_philo *philo, struct timeval now,
			struct timeval *is_not_thinking);

#endif
