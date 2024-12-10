#include "philo.h"

t_input	*save_input(char **argv)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	input->philo_count = ph_atoi(argv[1]);
	input->time_to_die = ph_atoi(argv[2]);
	input->time_to_eat = ph_atoi(argv[3]);
	input->time_to_sleep = ph_atoi(argv[4]);
	if (argv[5])
		input->must_eat = ph_atoi(argv[5]);
	else
		input->must_eat = INT_MIN;
	return (input);
}

void	allocate_forks(pthread_mutex_t *forks, t_input input)
{
	int	i;

	i = 0;
	while (i < input.philo_count)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			printf("Fork mutex init error\n");
		i++;
	}
}

void	allocate_philo(t_philo *philo, t_program *program, t_input *input)
{
	int	i;

	i = 0;
	while (i < input->philo_count)
	{
		philo[i].id = i + 1;
		philo[i].philo_count = input->philo_count;
		philo[i].start_time = philo[i].last_eaten = get_time();
		philo[i].times_eaten = 0;
		philo[i].input = input;
		philo[i].eating = 0;
		philo[i].dead = &program->dead_flag;
		philo[i].left_fork = &program->forks[i];
		philo[i].dead_lock = &program->dead_lock;
		philo[i].write_lock = &program->write_lock;
		philo[i].meal_lock = &program->meal_lock;
		if (i == 0)
			philo[i].right_fork = &program->forks[input->philo_count - 1];
		else
			philo[i].right_fork = &program->forks[i - 1];
		i++;
	}
	program->philo = philo;
}

void	initiate_program(t_program *program, t_philo *philo, t_input *input)
{
	program->dead_flag = 0;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	allocate_forks(program->forks, *input);
	allocate_philo(philo, program, input);
}