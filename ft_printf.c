/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:52:42 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/20 15:45:07 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flag(char *tab_flag, char c)
{
	int i;

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
	static char	tab_flag[8] = {'c', 's', 'p', 'd', 'u', 'x', 'X', 0};
	
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
		if (ft_check_flag(tab_flag, format[i]) != -1 && begin)
			tab_func[ft_check_flag(tab_flag, format[i])](argp);
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
