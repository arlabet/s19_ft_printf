/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 15:56:28 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/28 01:37:12 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_len_nbr(int nbr, int base)
{
	long int	n;
	int			i;

	n = nbr;
	i = 0;
	if (n < 0)
	{
		i = 1;
		n = n * -1;
	}
	while (n >= base)
	{
		n = n / base;
		i++;
	}
	return (i + 1);
}
