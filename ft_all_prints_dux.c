/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_dux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:38:59 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/13 12:02:52 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num(int nbr, const char *format, int i)
{
	int len;
	int nbr_space;
	int tmp;

	len = ft_len_nbr(nbr);
	if (ft_isdigit(format[i - 1]))
		nbr_space = ft_treat_space(format, i - 1, 1);
	tmp = ft_abs(nbr_space);
	if (tmp > len && tmp == nbr_space && ft_isdigit(format[i - 1])
		&& g_crop == 0 && ft_print_zero(format, i - 1) == 0)
		ft_print_spaces_format(tmp - len + 1);
	ft_putnbr_fd(nbr, 1);
	if (tmp > len && tmp != nbr_space && ft_isdigit(format[i - 1])
		&& g_crop == 0)
		ft_print_spaces_format(tmp - len + 1);
}

void	ft_print_num_uns(unsigned int nbr, const char *format, int i)
{
	ft_putnbr_u_fd(nbr, 1);
}

void	ft_print_hexlow(unsigned int nbr, const char *format, int i)
{
	ft_putnbr_base_fd(nbr, "0123456789abcdef", 1);
}

void	ft_print_hexup(unsigned int nbr, const char *format, int i)
{
	ft_putnbr_base_fd(nbr, "0123456789ABCDEF", 1);
}
