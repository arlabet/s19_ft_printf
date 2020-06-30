/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:52:42 by nsahloum          #+#    #+#             */
/*   Updated: 2020/06/28 22:37:11 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_apply_type(const char *format, int i, va_list argp)
{
	if (format[i] == 'c')
		ft_print_char(va_arg(argp, int), format, i);
	if (format[i] == 's')
		ft_print_string(va_arg(argp, char *));
	if (format[i] == 'p')
		ft_print_pointer(va_arg(argp, size_t));
	if (format[i] == 'd' || format[i] == 'i')
		ft_print_num(va_arg(argp, int));
	if (format[i] == 'u')
		ft_print_num_uns(va_arg(argp, unsigned int));
	if (format[i] == 'x')
		ft_print_hexlow(va_arg(argp, unsigned int));
	if (format[i] == 'X')
		ft_print_hexup(va_arg(argp, unsigned int));
	if (format[i] == '-')
		ft_print_spaces_after(format, i);
	//if (ft_isdigit(format[i]))
		// espace avant
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

void	ft_check_format(const char *format, va_list argp)
{
	int	i;
	int	begin;
	int stop;

	begin = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			begin = 1;
			i++;
		}
		if (format[i] == '%' && begin && i % 2 == 0)
			ft_putchar_fd('%', 1);
		if (ft_check_type(format[i]) && begin)
			ft_apply_type(format, i, argp);
		if (format[i] == '-' && begin == 1)
		{
			stop = 1;
			i++;
		}
		while (ft_isdigit(format[i]) && begin)
			i++;
		if (stop == 0)
			ft_putchar_fd(format[i], 1);
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
