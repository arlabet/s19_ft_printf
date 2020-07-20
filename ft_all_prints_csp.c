/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:57:15 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/20 21:56:37 by nsahloum         ###   ########.fr       */
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

void	ft_print_space(const char *format, int i)
{
	int nbr_space;
	int abs;
	int z;
	char c;

	while(ft_isdigit(format[i]) || format[i] == '-')
		i--;
	if (format[i + 1] == '0')
		c = '0';
	else
		c = ' ';
	nbr_space = atoi(&format[i + 1]);
	if (nbr_space < 0)
		ft_putchar_fd('%', 1);
	abs = ft_abs(nbr_space);
	z = abs - 1;
	while(z--)
		ft_putchar_fd(c, 1);
	if (abs == nbr_space)
		ft_putchar_fd('%', 1);
}

void	ft_stock(char *format, int i)
{
	
}