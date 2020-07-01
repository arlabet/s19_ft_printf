/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:57:15 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/01 02:05:17 by nsahloum         ###   ########.fr       */
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

void	ft_print_spaces(int nbr, int before_after_zero)
{
	char c;

	if (before_after_zero == 1 || before_after_zero == 0)
		c = 32;
	if (before_after_zero == 2)
		c = 48;
	if (before_after_zero == 1)
		ft_putchar_fd('%', 1);
	while (nbr > 1)
	{
		ft_putchar_fd(c, 1);
		nbr --;
	}
	if (before_after_zero == 0 || before_after_zero == 2)
		ft_putchar_fd('%', 1);
}
