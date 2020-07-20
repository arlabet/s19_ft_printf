/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:57:15 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/20 12:03:13 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list argp)
{
	char car;

	car = va_arg(argp, int);
	ft_putchar_fd(car, 1);
}

void	ft_print_string(va_list argp)
{
	char *str;

	str = va_arg(argp, char *);
	ft_putstr_fd(str, 1);
}

void	ft_print_pointer(va_list argp)
{
	size_t p;

	p = va_arg(argp, size_t);
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(p, "0123456789abcdef", 1);
}
