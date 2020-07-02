/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:57:15 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/02 03:08:37 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(int car, const char *format, int i)
{
	int nbr;
	int tmp;
	int	crop;
	
	if (ft_isdigit(format[i - 1]))
		nbr = ft_treat_space(format, i - 1, 1);
	tmp = ft_abs(nbr);
	if (tmp == nbr && ft_isdigit(format[i - 1]))
		ft_print_spaces_format(tmp);
	if (tmp != nbr && ft_isdigit(format[i - 1]))
		ft_print_spaces_format(tmp);
}

void	ft_print_string(char *str, const char *format, int i)
{
	int len;
	int nbr_space;
	int	tmp;
	int new_start;

	g_crop = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (ft_isdigit(format[i - 1]))
		nbr_space = ft_treat_space(format, i - 1, 1);
	tmp = ft_abs(nbr_space);
	if (tmp > len && tmp == nbr_space && ft_isdigit(format[i - 1]) 
		&& g_crop == 0)
		ft_print_spaces_format(tmp - len + 1);
	if (g_crop == 0 || (g_crop == 1 && tmp > len))
		ft_putstr_fd(str, 1);
	if (g_crop == 1)
		if (tmp < len)
			ft_putstr_fd(ft_substr(str, 0, tmp), 1);
	if (tmp > len && tmp != nbr_space && ft_isdigit(format[i - 1]) 
		&& g_crop == 0)
		ft_print_spaces_format(tmp - len + 1);
}

void	ft_print_pointer(size_t p, const char *format, int i)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(p, "0123456789abcdef", 1);
}
