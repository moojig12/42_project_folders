/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:51:22 by nmandakh          #+#    #+#             */
/*   Updated: 2024/06/25 13:51:23 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	save_input(t_program *program, char **argv)
{
	program->time_to_die = ph_atoi(argv[2]);
	program->time_to_eat = ph_atoi(argv[3]);
	program->time_to_sleep = ph_atoi(argv[4]);
	program->philo_count = ph_atoi(argv[1]);
	if (argv[5])
		program->times_to_eat_count = ph_atoi(argv[5]);
	else
		program->times_to_eat_count = INT_MIN;
}

void	initiate_program(t_program *program, t_philo *philo, char **argv)
{
	save_input(program, argv);
	program->found_dead = 0;
	program->philo = philo;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	return ;
}

void	initiate_forks(pthread_mutex_t *forks, int philo_count)
{
	int	i;

	i = 0;
	while (i < philo_count)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	initiate_philosophers(t_philo *philo,t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < program->philo_count)
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].state = &program->found_dead;
		philo[i].last_meal = get_current_time();
		philo[i].start_time = get_current_time();
		philo[i].time_to_die = program->time_to_die;
		philo[i].time_to_eat = program->time_to_eat;
		philo[i].time_to_sleep = program->time_to_sleep;
		philo[i].meal_lock = &program->meal_lock;
		philo[i].dead_lock = &program->dead_lock;
		philo[i].write_lock = &program->write_lock;
		philo[i].left_fork = &forks[i];
		if (i == 0)
			philo[i].right_fork = &forks[program->philo_count - 1];
		else
			philo[i].right_fork = &forks[i - 1];
		i++;
	}
}