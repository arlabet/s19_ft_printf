/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:52:42 by nsahloum          #+#    #+#             */
/*   Updated: 2020/03/11 23:51:28 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_type(char format, va_list argp)
{
	if (format == 'c')
		ft_print_char(va_arg(argp, int));
	if (format == 's')
		ft_print_string(va_arg(argp, char *));
	if (format == 'p')
		ft_print_pointer(va_arg(argp, size_t));
	if (format == 'd' || format == 'i')
		ft_print_num(va_arg(argp, int));
	if (format == 'u')
		ft_print_num_uns(va_arg(argp, unsigned int));
	if (format == 'x')
		ft_print_hexlow(va_arg(argp, unsigned int));
	if (format == 'X')
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

unsigned int	ft_treat_space(const char *format, int i)
{
	unsigned int	start;
	unsigned int	end;
	char			*toatoi;
	int				nbrspace;

	start = (unsigned int)i;
	while (ft_isdigit(format[i]))
		i++;
	end = i;
	toatoi = ft_substr(format, start, (end - start));
	nbrspace = ft_atoi(toatoi);
	while (nbrspace > 0)
	{
		ft_putchar_fd(' ', 1);
		nbrspace--;
	}
	return (end);
}

int		check_format(const char *format, va_list argp)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				ft_putchar_fd('%', 1);
			else if (ft_isdigit(format[i]))
				ft_treat_space(format, i);
			else if (check_type(format[i]) == 1)
				apply_type(format[i], argp);
			else if (check_type(format[i]) == 0 && !ft_isdigit(format[i]))
				ft_putchar_fd(format[i], 1);
		}
		else if (!ft_isdigit(format[i]) && check_type(format[i]) == 0)
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
