/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:52:42 by nsahloum          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/08/06 19:47:56 by nsahloum         ###   ########.fr       */
=======
/*   Updated: 2020/08/06 19:11:30 by nsahloum         ###   ########.fr       */
>>>>>>> b31d43f6c3983777719643f6e056937742afbd7a
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_space_format(int nbr, int zero, int neg)
{
	char c;

	c = (zero == 1) ? '0' : ' ';
	if (neg && zero)
		ft_putchar_fd('-', 1);
	if (!zero && neg && g_prec >= g_len && g_len != 0)
		nbr--;
	while (nbr--)
		ft_putchar_fd(c, 1);
}

int		ft_check_flag(char c)
{
	int			i;
	static char	tab_flag[10] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', 'o', 0};

	i = 0;
	while (tab_flag[i])
	{
		if (tab_flag[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_is_flag(const char *format, int i, int begin)
{
	if (begin)
	{
		while (ft_isdigit(format[i]) || format[i] == '-' || format[i] == '.' ||
		format[i] == '+' || format[i] == ' ' || format[i] == '*')
			i++;
	}
	return (i);
}

void	ft_check_format(const char *format, va_list argp)
{
	int			i;
	int			begin;

	i = 0;
	while (format[i])
	{
		ft_reset();
		begin = (format[i] == '%') ? 1 : 0;
		if (format[i] == '%' && ft_strlen(format) > 1)
			i++;
		i = ft_is_flag(format, i, begin);
		if ((i != 0 && (ft_isdigit(format[i - 1]) || format[i - 1] == '*' ||
		format[i - 1] == '.') && begin && format[i] == '%'))
			ft_print_space(format, i - 1, argp);
		if (ft_check_flag(format[i]) != -1 && begin && format[i - 1] == '*')
			ft_stock_star(format, i - 1, argp);
		if (ft_check_flag(format[i]) != -1 && begin &&
		(ft_isdigit(format[i - 1]) || format[i - 1] == '.'))
			ft_stock(format, i - 1, argp);
		if (ft_check_flag(format[i]) != -1 && begin)
			g_tab_func[ft_check_flag(format[i])](argp);
		else if (format[i] != '%' || (format[i] == '%' && format[i - 1] == '%'))
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
