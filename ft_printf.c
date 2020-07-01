/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:52:42 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/01 20:25:50 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_apply_type(const char *format, int i, va_list argp)
{
	if (format[i] == 'c')
		ft_print_char(va_arg(argp, int), format, i);
	if (format[i] == 's')
		ft_print_string(va_arg(argp, char *), format, i);
	if (format[i] == 'p')
		ft_print_pointer(va_arg(argp, size_t), format, i);
	if (format[i] == 'd' || format[i] == 'i')
		ft_print_num(va_arg(argp, int), format, i);
	if (format[i] == 'u')
		ft_print_num_uns(va_arg(argp, unsigned int), format, i);
	if (format[i] == 'x')
		ft_print_hexlow(va_arg(argp, unsigned int), format, i);
	if (format[i] == 'X')
		ft_print_hexup(va_arg(argp, unsigned int), format, i);
}

int		ft_check_type(char format)
{
	if (format == 'c' || format == 's' || format == 'p' || format == 'd'
	|| format == 'i' || format == 'u' || format == 'x' || format == 'X')
		return (1);
	else
		return (0);
}

void	ft_check_format(const char *format, va_list argp)
{
	int	i;
	int	begin;

	i = 0;
	while (format[i])
	{
		begin = 0;
		if (format[i] == '%' && ft_strlen(format) > 1)
		{
			begin = 1;
			i++;
		}
		if (format[i] == '%' && begin && i % 2)
			ft_putchar_fd('%', 1);
		while ((ft_isdigit(format[i]) || format[i] == '-') && begin)
			i++;
		if (ft_isdigit(format[i - 1]) && begin && format[i] == '%')
			ft_treat_space(format, i - 1, 0);
		if (ft_check_type(format[i]) && begin)
			ft_apply_type(format, i, argp);
		else if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		if (format[i])
			i++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	argp;

	g_nbrchar = 0;
	va_start(argp, format);
	ft_check_format(format, argp);
	va_end(argp);
	return (g_nbrchar);
}
