/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:57:15 by nsahloum          #+#    #+#             */
/*   Updated: 2020/06/27 00:23:16 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(int car, const char *format, int i)
{
	ft_putchar_fd(car, 1);
}

void	ft_print_string(char *str)
{
	ft_putstr_fd(str, 1);
}

void	ft_print_pointer(size_t p)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(p, "0123456789abcdef", 1);
}

void	ft_print_spaces(int nbr)
{
	char c;

	c = 32;
	while (nbr > 1)
	{
		ft_putchar_fd(c, 1);
		nbr --;
	}
}
