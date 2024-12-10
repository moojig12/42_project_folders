/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:40:15 by nmandakh          #+#    #+#             */
/*   Updated: 2023/12/06 17:32:04 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(long n, int base, int booly)
{
	int		i;
	char	*symbols;

	if (booly == 0)
		symbols = "0123456789abcdef";
	else if (booly == 1)
		symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_print_char('-');
		return (ft_print_digit(-n, base, booly) + 1);
	}
	else if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		i = ft_print_digit(n / base, base, booly);
		return (i + ft_print_digit(n % base, base, booly));
	}
}
