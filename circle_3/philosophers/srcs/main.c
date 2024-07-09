/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:51:18 by nmandakh          #+#    #+#             */
/*   Updated: 2024/06/25 13:52:10 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// argv[1] — The number of philosophers
// argv[2] — The time a philosopher will die if he doesn’t eat
// argv[3] — The time it takes a philosopher to eat
// argv[4] — The time it takes a philosopher to sleep
// argv[5] — Number of times all the philosophers need to eat before terminating the program **

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philo[MAX];
	pthread_mutex_t	forks[MAX];

	if (preliminary_check(argc, argv))
		return (1);
	// initiation
	initiate_program(&program, philo, argv);
	initiate_forks(forks, program.philo_count);
	initiate_philosophers(philo, &program, forks, argv);
	// start threads
	create_threads(&program, forks);
}