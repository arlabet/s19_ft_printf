/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:52:42 by nsahloum          #+#    #+#             */
/*   Updated: 2020/03/12 04:08:00 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_type(const char *format, int i, va_list argp)
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
	return (0);
}

int		check_type(char format)
{
	if (format == 'c' || format == 's' || format == 'p' || format == 'd'
	|| format == 'i' || format == 'u' || format == 'x' || format == 'X')
		return (1);
	else
		return (0);
}

int	ft_treat_space(const char *format, int i)
{
	const char	*tmp;
	int			nbr;

	while (ft_isdigit(format[i]))
		i--;
	tmp = &format[i + 1];
	nbr = ft_atoi(tmp);
	return (nbr);
}

int		check_format(const char *format, va_list argp)
{
	int	i;
	int begin;

	begin = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			begin = 1;
			i++;
		}
		if (format[i] == '%' && begin)
			ft_putchar_fd('%', 1);
		while (ft_isdigit(format[i]) && begin)
			i++;
		if (check_type(format[i]) && begin)
			apply_type(format, i, argp);
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	argp;

	g_nbrchar = 0;
	va_start(argp, format);
	check_format(format, argp);
	va_end(argp);
	return (g_nbrchar);
}
