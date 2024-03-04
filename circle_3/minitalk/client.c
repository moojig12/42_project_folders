/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:20:12 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/04 12:40:39 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	sig_handle(int signum)
{
	ft_printf("Message received\nSignum: %i\n", signum);
}

void	signal_message(char *pid, char *message)
{
	int	i;
	int	j;
	int	bit;
	unsigned char octet;

	j = 0;
	while (*message)
	{
		octet = *message;
		i = 0;
		while (i < 8)
		{
			bit = (octet >> i) & 1;
			if (bit == 0)
				kill(ft_atoi(pid), SIGUSR1);
			else
				kill(ft_atoi(pid), SIGUSR2);
			i++;
			usleep(100);
		}
		message++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		return (0);
	signal_message(argv[1], argv[2]);
	/* while (1)
	{
		signal(SIGUSR1, sig_handle);
		signal(SIGUSR2, sig_handle);
	} */
}