/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_others.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:42:25 by nsahloum          #+#    #+#             */
/*   Updated: 2020/06/30 21:55:13 by nsahloum         ###   ########.fr       */
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

void *ft_assign_fct(void (*tab_funct[7]) (va_list))
{
	tab_funct[0] = ft_print_char;
	tab_funct[1] = ft_print_string;
	tab_funct[2] = ft_print_pointer;
	tab_funct[3] = ft_print_num;
	tab_funct[4] = ft_print_num_uns;
	tab_funct[5] = ft_print_hexlow;
	tab_funct[6] = ft_print_hexup;

	return(tab_funct);
}