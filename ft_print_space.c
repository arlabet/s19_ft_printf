/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:31:43 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/01 01:02:47 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_space(const char *format)
{
	int end;
	char *tmp;
	int nbr_space;
	
	end = 0;
	if (format[end] == '-')
	{
		ft_putchar_fd('%', 1);
		end++;
	}
	while (ft_isdigit(format[end]))
		end++;
	tmp = ft_substr(format, 0, end);
	nbr_space = ft_atoi(tmp);
	while (nbr_space > 0)
		ft_putchar_fd(' ', 1);
	if (ft_isdigit(format[0]))
		ft_putchar_fd('%', 1);
}