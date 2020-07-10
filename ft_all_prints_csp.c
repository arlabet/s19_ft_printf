/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:57:15 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/10 16:27:06 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(int car, const char *format, int i)
{
	int nbr;
	int tmp;

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

	g_crop = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (format[i - 1] == '.')
		ft_print_spaces(ft_treat_space(format, i - 2, 1), 1, 0);
	if (ft_print_zero(format, i - 1) == 1 && len < ft_treat_space(format, i - 1, 1))
		ft_print_spaces((ft_treat_space(format, i - 1, 1)) - len, 2, 0);
	if (ft_isdigit(format[i - 1]))
		nbr_space = ft_treat_space(format, i - 1, 1);
	tmp = ft_abs(nbr_space);
	if (tmp > len && tmp == nbr_space && ft_isdigit(format[i - 1])
		&& g_crop == 0 && ft_print_zero(format, i - 1) == 0)
		ft_print_spaces_format(tmp - len + 1);
	if (g_crop == 0 && format[i - 1] != '.')
		ft_putstr_fd(str, 1);
	if (g_crop == 1)
		print_crop_space(str, tmp, i, format);
	if (g_crop == 2)
		ft_only_crop(str, tmp);
	if (tmp > len && tmp != nbr_space && ft_isdigit(format[i - 1])
		&& g_crop == 0)
		ft_print_spaces_format(tmp - len + 1);
}

void	print_crop_space(char *str, int tmp, int i, const char *format)
{
	if (tmp > ft_strlen(str))
		tmp = ft_strlen(str);
	if (crop_space(format, i) > 0 && crop_space(format, i) > tmp)
		ft_print_spaces_format((crop_space(format, i) - tmp + 1));
	if (tmp < ft_strlen(str))
		ft_putstr_fd(ft_substr(str, 0, tmp), 1);
	else if (tmp >= ft_strlen(str))
		ft_putstr_fd(str, 1);
	if (crop_space(format, i) < 0 && (crop_space(format, i) * (-1)) > tmp)
		ft_print_spaces_format((crop_space(format, i) * (-1)) - tmp + 1);
}

int		crop_space(const char *format, int i)
{
	int nbr_space;

	i--;
	nbr_space = 0;
	while (ft_isdigit(format[i]))
		i--;
	if (format[i] == '.' && ft_isdigit(format[i - 1]))
		nbr_space = ft_treat_space(format, i - 1, 1);
	return (nbr_space);
}

void	ft_print_pointer(size_t p, const char *format, int i)
{
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd(p, "0123456789abcdef", 1);
}
