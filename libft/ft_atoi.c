/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:47:02 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/22 15:44:50 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	n;
	int		neg;

	neg = 0;
	n = 0;
	if (!str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			neg = 1;
	while (ft_isdigit(*str))
	{
		n = (n * 10) + *str++ - 48;
		if (n < 0)
			return ((neg) ? 0 : -1);
	}
	return ((neg) ? -n : n);
}
