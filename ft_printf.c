/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:52:42 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/20 17:00:26 by nsahloum         ###   ########.fr       */
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
		if (ft_check_flag(format[i]) != -1 && begin && ft_check_flag(format[i]) != 7)
			g_tab_func[ft_check_flag(format[i])](argp);
		if (begin && format[i - 1] == '%' && ft_isdigit(format[i]) && i != 0)
		{
			//printf("check flag");
			ft_print_space(format, i);
			while (ft_isdigit(format[i]))
				i++;
		}
		else if (format[i] != '%')
		{
			//printf("putchar");
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
