/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:20:14 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/02 18:48:46 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	*sig_handler(int signum)
{
	static unsigned char	letter;
	static int	i;

	i = 0;
	if (signal == SIGUSR1)
		letter |= (0 << i);
	else
		letter |= (1 << i);
	if (i == 8)
	{
		i = 0;
		ft_putchar_fd(letter, 1);
		letter = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	//	Print PID
	ft_printf("PID: [%i]\n", pid);

	//	Create endless loop for receiving signals
	//		Receive signals
	//		Decrypt signals
	//		Take action for Signal
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
	}
}