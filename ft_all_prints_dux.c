/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_dux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:38:59 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/25 02:47:47 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num(va_list argp)
{
	int nbr;
	int zero;
	int neg;

	nbr = va_arg(argp, int);
	g_len = ft_len_nbr(nbr, 10);
	neg = (nbr < 0 && (g_prec > g_len || (g_w && g_w[0] == '0'))) ? 1 : 0;
	nbr = (neg && ((g_prec > 0 && g_prec > g_len) || (g_w && g_w[0] == '0' &&
	g_width > g_len && g_prec < 0))) ? ft_abs(nbr) : nbr;
	if (g_width > 0)
	{
		zero = (g_w && g_w[0] == '0' && g_prec < 0) ? 1 : 0;
		g_len = (g_prec == 0 || g_prec > g_len) ? g_prec : g_len;
		if (g_width > g_len)
			ft_print_space_format(g_width - g_len, zero, neg);
	}
	if (g_prec > 0 && g_prec > ft_len_nbr(nbr, 10))
		ft_print_space_format(g_prec - ft_len_nbr(nbr, 10), 1, neg);
	if (g_prec != 0)
		ft_putnbr_fd(nbr, 1);
	if (g_width < 0 && ft_abs(g_width) > g_len)
	{
		g_len = (g_prec == 0 || g_prec > g_len) ? g_prec : g_len;
		ft_print_space_format(ft_abs(g_width) - g_len, 0, neg);
	}
}

void	ft_print_num_uns(va_list argp)
{
	unsigned int	nbr;
	int				zero;
	int				neg;

	nbr = va_arg(argp, unsigned int);
	g_len = ft_len_nbr(nbr, 10);
	neg = (nbr < 0 && (g_prec > g_len || (g_w && g_w[0] == '0'))) ? 1 : 0;
	nbr = (neg && ((g_prec > 0 && g_prec > g_len) || (g_w && g_w[0] == '0' &&
	g_width > g_len && g_prec < 0))) ? ft_abs(nbr) : nbr;
	if (g_width > 0)
	{
		zero = (g_w && g_w[0] == '0' && g_prec < 0) ? 1 : 0;
		g_len = (g_prec == 0 || g_prec > g_len) ? g_prec : g_len;
		if (g_width > g_len)
			ft_print_space_format(g_width - g_len, zero, neg);
	}
	if (g_prec > 0 && g_prec > ft_len_nbr(nbr, 10))
		ft_print_space_format(g_prec - ft_len_nbr(nbr, 10), 1, neg);
	if (g_prec != 0)
		ft_putnbr_u_fd(nbr, 1);
	if (g_width < 0 && ft_abs(g_width) > g_len)
	{
		g_len = (g_prec == 0 || g_prec > g_len) ? g_prec : g_len;
		ft_print_space_format(ft_abs(g_width) - g_len, 0, neg);
	}
}

void	ft_print_hexlow(va_list argp)
{
	unsigned int	nbr;
	int				zero;
	int				neg;

	nbr = va_arg(argp, unsigned int);
	g_len = ft_len_nbr(nbr, 16);
	neg = (nbr < 0 && (g_prec > g_len || (g_w && g_w[0] == '0'))) ? 1 : 0;
	nbr = (neg && ((g_prec > 0 && g_prec > g_len) || (g_w && g_w[0] == '0' &&
	g_width > g_len && g_prec < 0))) ? ft_abs(nbr) : nbr;
	if (g_width > 0)
	{
		zero = (g_w && g_w[0] == '0' && g_prec < 0) ? 1 : 0;
		g_len = (g_prec == 0 || g_prec > g_len) ? g_prec : g_len;
		if (g_width > g_len)
			ft_print_space_format(g_width - g_len, zero, neg);
	}
	if (g_prec > 0 && g_prec > ft_len_nbr(nbr, 16))
		ft_print_space_format(g_prec - ft_len_nbr(nbr, 16), 1, neg);
	if (g_prec != 0)
		ft_putnbr_base_fd(nbr, "0123456789abcdef", 1);
	if (g_width < 0 && ft_abs(g_width) > g_len)
	{
		g_len = (g_prec == 0 || g_prec > g_len) ? g_prec : g_len;
		ft_print_space_format(ft_abs(g_width) - g_len, 0, neg);
	}
}

void	ft_print_hexup(va_list argp)
{
	unsigned int	nbr;
	int				zero;
	int				neg;

	nbr = va_arg(argp, unsigned int);
	g_len = ft_len_nbr(nbr, 16);
	neg = (nbr < 0 && (g_prec > g_len || (g_w && g_w[0] == '0'))) ? 1 : 0;
	nbr = (neg && ((g_prec > 0 && g_prec > g_len) || (g_w && g_w[0] == '0' &&
	g_width > g_len && g_prec < 0))) ? ft_abs(nbr) : nbr;
	if (g_width > 0)
	{
		zero = (g_w && g_w[0] == '0' && g_prec < 0) ? 1 : 0;
		g_len = (g_prec == 0 || g_prec > g_len) ? g_prec : g_len;
		if (g_width > g_len)
			ft_print_space_format(g_width - g_len, zero, neg);
	}
	if (g_prec > 0 && g_prec > ft_len_nbr(nbr, 16))
		ft_print_space_format(g_prec - ft_len_nbr(nbr, 16), 1, neg);
	if (g_prec != 0)
		ft_putnbr_base_fd(nbr, "0123456789ABCDEF", 1);
	if (g_width < 0 && ft_abs(g_width) > g_len)
	{
		g_len = (g_prec == 0 || g_prec > g_len) ? g_prec : g_len;
		ft_print_space_format(ft_abs(g_width) - g_len, 0, neg);
	}
}

void	ft_crop(char *str, int end)
{
	int i;

	i = 0;
	if (end == 0 || end >= ft_strlen(str))
		ft_putstr_fd(str, 1);
	while (i < end && end < ft_strlen(str))
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}
