/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_dux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:38:59 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/21 14:39:20 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num(va_list argp)
{
	int nbr;

	nbr = va_arg(argp, int);
	ft_putnbr_fd(nbr, 1);
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
