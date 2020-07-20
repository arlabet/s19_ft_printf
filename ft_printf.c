/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:52:42 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/20 17:16:08 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flag(char c)
{
	int i;
	static char	tab_flag[9] = {'c', 's', 'p', 'd', 'u', 'x', 'X', '%', 0};

	i = 0;
	while (tab_flag[i])
	{
		if (tab_flag[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_is_flag(char c)
{
	if (ft_isdigit(c) || c == '-' || c == '.')
		return (1);
	return (0);
}

void	ft_check_format(const char *format, va_list argp)
{
	int			i;
	int			begin;
	
	i = 0;
	while (format[i])
	{
		begin = 0;
		if (format[i] == '%' && ft_strlen(format) > 1)
		{
			begin = 1;
			i++;
		}
		if (format[i] == '%' && format[i - 1] == '%' && i != 0)
			ft_putchar_fd('%', 1);
		while (ft_is_flag(format[i]) && begin)
			i++;
		if (ft_isdigit(format[i - 1]) && begin && format[i] == '%')
			ft_print_space(format, i - 1);
		else if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
		}
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
