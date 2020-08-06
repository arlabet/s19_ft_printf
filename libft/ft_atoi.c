/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:47:02 by nsahloum          #+#    #+#             */
/*   Updated: 2020/08/06 20:23:32 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	long	n;
	int		neg;
	int		i;

	i = 0;
	neg = 0;
	n = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '0')
		i++;
	if (str[i] == '-')
		neg = 1;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + str[i] - 48;
		if (n < 0)
			return ((neg) ? 0 : -1);
		i++;
	}
	return ((neg) ? -n : n);
}
