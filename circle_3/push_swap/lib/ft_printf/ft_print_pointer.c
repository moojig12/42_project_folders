/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:28:11 by nmandakh          #+#    #+#             */
/*   Updated: 2023/12/06 17:39:45 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_digit_p(uintptr_t n, uintptr_t base, int booly)
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
		return (ft_print_digit_p(-n, base, booly) + 1);
	}
	else if (n < base)
		return (ft_print_char(symbols[n]));
	else
	{
		i = ft_print_digit_p(n / base, base, booly);
		return (i + ft_print_digit_p(n % base, base, booly));
	}
}

int	ft_print_pointer(void *p)
{
	uintptr_t	num;

	if (!p)
		return (ft_print_string("(nil)"));
	num = (uintptr_t) p;
	ft_print_string("0x");
	return (ft_print_digit_p(num, 16, 0) + 2);
}
