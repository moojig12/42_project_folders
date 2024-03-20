/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:20:14 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/20 11:24:46 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	sig_handler(int signum)
{
	static unsigned char	letter = 0;
	static int				i = 0;

	if (signum == SIGUSR1)
		letter |= (0 << i);
	else
		letter |= (1 << i);
	i++;
	if (i == 8)
	{
		if (letter == 0)
			ft_putchar_fd('\n', 1);
		ft_putchar_fd(letter, 1);
		letter = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: [%i]\n", pid);
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
	}
}
