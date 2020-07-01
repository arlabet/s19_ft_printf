/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:57:15 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/01 19:42:06 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(int car, const char *format, int i)
{
	int nbr;
	int tmp;
	
	nbr = 0;
	if (ft_isdigit(format[i - 1]))
		nbr = ft_treat_space(format, i - 1, 1);
	tmp = ft_abs(nbr);
	if (tmp == nbr && ft_isdigit(format[i - 1]))
		ft_print_spaces_format(tmp);
	ft_putchar_fd(car, 1);
	if (tmp != nbr && ft_isdigit(format[i - 1]))
		ft_print_spaces_format(tmp);
}

void	ft_print_string(char *str, const char *format, int i)
{
	int len;
	int nbr_space;
	int	tmp;
	
	len = ft_strlen(str);
	if (ft_isdigit(format[i - 1]))
		nbr_space = ft_treat_space(format, i- 1, 1);
	tmp = ft_abs(nbr_space);
	if (tmp > len && tmp == nbr_space && ft_isdigit(format[i - 1]))
		ft_print_spaces_format(tmp - len + 1);
	ft_putstr_fd(str, 1);
	if (tmp > len && tmp != nbr_space && ft_isdigit(format[i - 1]))
		ft_print_spaces_format(tmp - len + 1);
}

void	ft_print_pointer(size_t p, const char *format, int i)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(p, "0123456789abcdef", 1);
}
