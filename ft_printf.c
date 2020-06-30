/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:52:42 by nsahloum          #+#    #+#             */
/*   Updated: 2020/06/30 17:24:43 by nsahloum         ###   ########.fr       */
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

int		ft_check_type(char format)
{
	if (format == 'c' || format == 's' || format == 'p' || format == 'd'
	|| format == 'i' || format == 'u' || format == 'x' || format == 'X'
	|| format == '-' || ft_isdigit(format))
		return (1);
	else
		return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list	argp;
	struct s_flags print_functions;
	int i;

	i = 0;
	g_nbrchar = 0;
	
	va_start(argp, format);
	while (format[i])
	{
		if (i != 0 && format[i - 1] == '%')
		{
			if (ft_check_type(format[i]))
				print_functions.s(argp);
			i++;
		}
		i++;
	}
	va_end(argp);
	return (g_nbrchar);
}
