/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:57:15 by nsahloum          #+#    #+#             */
/*   Updated: 2020/03/12 04:09:12 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(int car, const char *format, int i)
{
	int spaces;

	spaces = 0;
	if (ft_isdigit(format[i - 1]))
		spaces = ft_treat_space(format, i - 1);
	while (--spaces)
		ft_putchar_fd(' ', 1);
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
