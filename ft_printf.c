/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:52:42 by nsahloum          #+#    #+#             */
/*   Updated: 2020/06/30 22:14:23 by nsahloum         ###   ########.fr       */
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

int		ft_check_type(char c)
{
	int		i;
	char	tab_type[8];

	tab_type[0] = 'c';
	tab_type[1] = 's';
	tab_type[2] = 'p';
	tab_type[3] = 'd';
	tab_type[4] = 'u';
	tab_type[5] = 'x';
	tab_type[6] = 'X';
	tab_type[7] = '\0';
	i = 0;
	while (tab_type[i])
	{
		if (tab_type[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int		ft_printf(const char *format, ...)
{
	void	(*func_to_call) (va_list);
	va_list	argp;
	int		i;
	int		t;

	t = -1;
	i = 0;
	g_nbrchar = 0;
	va_start(argp, format);
	void	(*tab_funct[7]) (va_list);
	ft_assign_fct(tab_funct);
	while (format[i])
	{
		if (i != 0 && format[i - 1] == '%' && format[i] == '%' && i % 2)
			ft_putchar_fd('%', 1);
		if (i != 0 && format[i - 1] == '%')
		{
			if (ft_check_type(format[i]) != -1)
			{
				t = ft_check_type(format[i]);
				func_to_call = tab_funct[t];
				func_to_call(argp);
			}
		}
		if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(argp);
	return (g_nbrchar);
}
