/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 22:25:06 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/01 00:31:04 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list argp)
{
	char c;

	c = va_arg(argp, int);
	ft_putchar_fd(c, 1);
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