/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:20:14 by nmandakh          #+#    #+#             */
/*   Updated: 2024/03/02 18:00:03 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	sig_handler(int signum)
{
	ft_printf("Terminating Program!\n");
	exit (0);
}



int	main(int argc, char **argv)
{
	signal(SIGINT, sig_handler);
	signal(SIGTERM, sig_handler);
	//	Print PID
	ft_printf("PID: %i\n", getpid);

	//	Create endless loop for receiving signals
	//		Receive signals
	//		Decrypt signals
	//		Take action for Signal
	while (1)
	{
		exit (0);
	}
}