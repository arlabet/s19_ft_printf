/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_dux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:38:59 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/21 18:46:39 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num(va_list argp)
{
	int nbr;
	int nbr_space;
	int zero;
	int len;

	zero = (g_prec > 0 || (g_w && g_w[0] == '0')) ? 1 : 0;
	nbr = va_arg(argp, int);
	len = ft_len_nbr(nbr);
	if (nbr < 0 && zero == 1)
	{
		ft_putchar_fd('-', 1);
		nbr = ft_abs(nbr);
		if (g_prec > 0)
			len--;
	}
	nbr_space = (g_width != 0 && ft_abs(g_width) > len) ? 
	ft_abs(g_width) - len : 0;
	if (g_width == 0 && g_prec > 0 && g_prec > len)
		nbr_space = g_prec - len;
	if ((nbr_space > 0 && (g_width == ft_abs(g_width))) || g_prec > 0)
		ft_print_space_format(nbr_space, zero);
	if (g_prec != 0)
		ft_putnbr_fd(nbr, 1);
	if (nbr_space > 0 && g_width != ft_abs(g_width))
		ft_print_space_format(nbr_space, zero);
	ft_reset();
}

void	ft_print_num_uns(va_list argp)
{
	unsigned int nbr;

	nbr = va_arg(argp, unsigned int);
	ft_putnbr_u_fd(nbr, 1);
}

void	ft_print_hexlow(va_list argp)
{
	unsigned int nbr;

	nbr = va_arg(argp, unsigned int);
	ft_putnbr_base_fd(nbr, "0123456789abcdef", 1);
}

void	ft_print_hexup(va_list argp)
{
	unsigned int nbr;

	nbr = va_arg(argp, unsigned int);
	ft_putnbr_base_fd(nbr, "0123456789ABCDEF", 1);
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
