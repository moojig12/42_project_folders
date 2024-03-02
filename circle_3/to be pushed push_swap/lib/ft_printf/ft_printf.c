/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandakh <nmandakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:39:25 by nmandakh          #+#    #+#             */
/*   Updated: 2023/12/06 17:52:06 by nmandakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(char value, va_list list)
{
	int	i;

	i = 0;
	if (value == 'c')
		i += ft_print_char(va_arg(list, int));
	else if (value == 's')
		i += ft_print_string(va_arg(list, char *));
	else if (value == 'p')
		i += ft_print_pointer(va_arg(list, void *));
	else if (value == 'd')
		i += ft_print_digit(va_arg(list, int), 10, 0);
	else if (value == 'i')
		i += ft_print_digit(va_arg(list, int), 10, 0);
	else if (value == 'u')
		i += ft_print_digit(va_arg(list, unsigned int), 10, 0);
	else if (value == 'x')
		i += ft_print_digit(va_arg(list, unsigned int), 16, 0);
	else if (value == 'X')
		i += ft_print_digit(va_arg(list, unsigned int), 16, 1);
	else
		i += write(1, &value, 1);
	return (i);
}

int	ft_printf(const char *s1, ...)
{
	va_list	list;
	int		i;

	i = 0;
	va_start(list, s1);
	if (!s1)
		return (-1);
	while (*s1 != '\0')
	{
		if (*s1 == '%')
			i += ft_print_format(*(++s1), list);
		else
			i += write(1, s1, 1);
		s1++;
	}
	va_end(list);
	return (i);
}
