/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:57:15 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/21 18:16:31 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list argp)
{
	char car;

	car = va_arg(argp, int);
	ft_putchar_fd(car, 1);
}

void	ft_print_string(va_list argp)
{
	char *str;
	int len;
	int nbr_space;
	int zero;

	zero = (g_w && g_w[0] == '0') ? 1 : 0;
	nbr_space = 0;
	str = va_arg(argp, char *);
	if (str == NULL)
		str = "(null)";
	len = ((g_prec < ft_strlen(str) && g_prec != 0) || g_noprint_s == -1) ? 
	g_prec : ft_strlen(str);
	if (g_width > 0)
		nbr_space = (g_width > len) ? g_width - len : 0;
	else if (g_width < 0)
		nbr_space = (ft_abs(g_width) > len) ? ft_abs(g_width) - len : 0;
	if (nbr_space > 0 && ft_abs(g_width) == g_width)
		ft_print_space_format(nbr_space, zero);
	if (g_prec != 0)
		ft_crop(str, g_prec);
	if (nbr_space > 0 && ft_abs(g_width) != g_width)
		ft_print_space_format(nbr_space, zero);
}

void	ft_print_pointer(va_list argp)
{
	size_t p;

	p = va_arg(argp, size_t);
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(p, "0123456789abcdef", 1);
}

void	ft_print_space(const char *format, int i)
{
	int nbr_space;
	int abs;
	int z;
	char c;

	while(ft_isdigit(format[i]) || format[i] == '-')
		i--;
	if (format[i + 1] == '0')
		c = '0';
	else
		c = ' ';
	nbr_space = atoi(&format[i + 1]);
	if (nbr_space < 0)
		ft_putchar_fd('%', 1);
	abs = ft_abs(nbr_space);
	z = abs - 1;
	while(z--)
		ft_putchar_fd(c, 1);
	if (abs == nbr_space)
		ft_putchar_fd('%', 1);
}

void	ft_stock(const char *format, int i)
{
	if ((format[i] == '.' && !ft_isdigit(format[i + 1])) || 
	(format[i] == '0' && format[i - 1] == '.'))
		g_noprint_s = -1;
	while (ft_isdigit(format[i]) || format[i] == '-' || format[i] == '+')
		i--;
	if (format[i] == '.')
	{
		g_p = &format[i + 1];
		g_prec = ft_atoi(&format[i + 1]);
		if (g_prec == 0)
			g_noprint_s = -1;
	}
	if (format[i] != '.' || (format[i] == '.' && ft_isdigit(format[i - 1])))
	{
		if (format[i] == '.')
			i--;
		while (ft_isdigit(format[i]) || format[i] == '-' || format[i] == '+')
			i--;
		g_w = &format[i + 1];
		g_width = ft_atoi(&format[i + 1]);
	}
}
