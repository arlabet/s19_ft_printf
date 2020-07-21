/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:52:42 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/21 18:16:42 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_space_format(int nbr, int zero)
{
	char c;
	
	c = (zero == 1) ? '0' : ' ';
	while(nbr--)
		ft_putchar_fd(c, 1);
}

int		ft_check_flag(char c)
{
	int i;
	static char	tab_flag[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', 0};

	i = 0;
	while (tab_flag[i])
	{
		if (tab_flag[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_is_flag(const char *format, int i)
{
	if (ft_isdigit(format[i]) || format[i] == '-' || format[i] == '.')
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
		ft_reset();
		begin = 0;
		if (format[i] == '%' && ft_strlen(format) > 1)
		{
			begin = 1;
			i++;
		}
		while (ft_is_flag(format, i) && begin)
			i++;
		if (i != 0 && ft_isdigit(format[i - 1]) && begin && format[i] == '%')
			ft_print_space(format, i - 1);
		if (ft_check_flag(format[i]) != -1 && begin && (ft_isdigit(format[i - 1]) 
		|| format[i - 1] == '.'))
			ft_stock(format, i - 1);
		if(ft_check_flag(format[i]) != -1 && begin)
			g_tab_func[ft_check_flag(format[i])](argp);
		else if (format[i] != '%' || (format[i] == '%' && format[i - 1] == '%'))
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
