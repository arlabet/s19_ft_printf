/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 10:59:27 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/13 13:38:29 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_nbr(int nbr)
{
	int i;

	i = 0;
	if (nbr < 0)
		i = 1;
	nbr = ft_abs(nbr);
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		i++;
	}
	return(i + 1);
}

int ft_space_num(const char *format, int end)
{
	int start;
	char *tmp;
	
	start = end;
	while (ft_isdigit(format[start]))
		start--;
	tmp = ft_substr(format, start + 1, end - start + 1);
	if (format[start] == '-')
		return (atoi(tmp) * -1);
	return(atoi(tmp));
}