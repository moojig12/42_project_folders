#include "philo.h"

// argv[1] -	The number of philosophers
// argv[2] -	The time a philosopher will die if he doesn’t eat
// argv[3] -	The time it takes a philosopher to eat
// argv[4] -	The time it takes a philosopher to sleep
/* argv[5] -	Number of times all the philosophers 
				need to eat before terminating the program ** */

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philo[200];
	pthread_mutex_t	forks[200];
	t_input			*input;

	if (pre_check(argc, argv))
		return (1);
	input = save_input(argv);
	program.forks = forks;
	initiate_program(&program, philo, input);
	create_threads(&program, philo, input);
	destroy_all(&program);
}