/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:52:42 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/01 00:51:12 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_check_format(const char *format, va_list argp)
{
	int	i;
	void	(*tab_funct[7]) (va_list);
	int space_before;
	int space_after;
	
	ft_assign_fct(tab_funct);
	i = 0;
	space_before = 0;
	space_after = 0;
	while (format[i])
	{
		if (i != 0 && (ft_isdigit(format[i]) || format[i] == '-') && 
				format[i - 1] == '%' )
			ft_print_space(&format[i]);
		if (i != 0 && format[i] == '%' && format[i - 1] == '%' && i % 2)
			ft_putchar_fd('%', 1);
		if (format[i] == '%')
			i++;
		if (ft_check_type(format[i]) != -1 && format[i - 1] == '%')
			tab_funct[ft_check_type(format[i])](argp);
		else
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
