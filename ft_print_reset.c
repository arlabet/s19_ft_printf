/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:42:57 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/25 15:28:59 by nsahloum         ###   ########.fr       */
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
}

int		ft_len_pointer(size_t nbr)
{
	long int	n;
	int			i;

	n = nbr;
	i = 0;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i + 1);
}

void	ft_stock_star(const char *format, int i, int star, va_list argp)
{
		while (format[i] == '*' || format[i] == '.')
			i--;
		i++;
		if (format[i] == '*' && format[i - 1] != '.')
			g_width = va_arg(argp, int);
		if (format[i - 1] == '-' && g_width != 0)
			g_width = (g_width < 0) ? g_width : g_width * (-1);
		if (format[i + 1] == '.')
			g_prec = va_arg(argp, int);
		if (format[i] == '.')
			g_prec = va_arg(argp, int);
		
		g_w = (g_width != 0 && format[i - 1] == '0') ? "00" 
		: ft_itoa(g_width);
		g_p  = ft_itoa(g_prec);
}

void	ft_is_space(char c, int begin)
{
	if (c == ' ' && begin)
		ft_putchar_fd(' ', 1);
}