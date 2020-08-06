/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:42:57 by nsahloum          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/08/06 19:48:03 by nsahloum         ###   ########.fr       */
=======
/*   Updated: 2020/08/06 19:11:07 by nsahloum         ###   ########.fr       */
>>>>>>> b31d43f6c3983777719643f6e056937742afbd7a
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset(void)
{
	g_width = 0;
	g_prec = -1;
	g_p = NULL;
	g_w = NULL;
	g_len = 0;
	g_space = 0;
	g_star = 0;
}

int		ft_len_pointer(size_t nbr)
{
	long unsigned int	n;
	int					i;

	n = nbr;
	i = 0;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i + 1);
}

void	ft_stock_star(const char *format, int i, va_list argp)
{
	int space;
	int is_star;

	space = 0;
	g_star = 1;
	is_star = 1;
	while (format[i] == '*' || format[i] == '.')
		i--;
	i++;
	if (format[i] == '*' && format[i - 1] != '.')
		g_width = va_arg(argp, int);
	if (format[i - 1] == '-' && g_width != 0)
		g_width = (g_width < 0) ? g_width : g_width * (-1);
	if (format[i + 1] == '.' || format[i] == '.')
		g_prec = va_arg(argp, int);
	if (format[i] == '.' && ft_isdigit(format[i - 1]))
	{
		ft_w_not_star(format, i - 1);
		is_star = 0;
	}
	if (is_star == 1)
		g_w = (g_width != 0 && format[i - 1] == '0') ? "00"
		: NULL;
}

void	ft_w_not_star(const char *format, int i)
{
	while (ft_isdigit(format[i]) || format[i] == '-' || format[i] == '+')
		i--;
	g_width = ft_atoi(&format[i + 1]);
	g_w = &format[i + 1];
}
