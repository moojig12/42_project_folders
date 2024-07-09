/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:51:30 by nmandakh          #+#    #+#             */
/*   Updated: 2024/06/25 13:56:30 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ph_print(char *message, int fd)
{
	int	len;

	len = 0;
	while (message[len])
	{
		len++;
	}
	write(fd, message, len);
	if (fd == 2)
		return (1);
	else
		return (0);
}

int	ph_atoi(char *input)
{
	int	count;
	int	number;
	int	sign;

	count = 0;
	sign = 1;
	while (input[count] == ' ' || (9 <= input[count] && input[count] <= 13))
		count++;
	if (input[count] == '-' || input[count] == '+')
	{
		if (input[count] == '-')
			sign *= -1;
		count++;
	}
	number = 0;
	while ('0' <= input[count] && input[count] <= '9')
	{
		number = (number * 10) + ((input[count] - '0'));
		count++;
	}
	return (sign * number);
}

void	destory_mutex(t_program *program, pthread_mutex_t *forks, char *output)
{
	int	i;

	i = 0;
	if (output)
	{
		write(2, output, ft_strlen(output));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->philo_count)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}