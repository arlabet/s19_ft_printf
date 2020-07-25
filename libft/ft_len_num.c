/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 15:56:28 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/25 02:45:44 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_nbr(int nbr, int base)
{
	int i;

	i = 0;
	if (nbr < 0)
		i = 1;
	nbr = ft_abs(nbr);
	while (nbr >= base)
	{
		nbr = nbr / base;
		i++;
	}
	return (i + 1);
}
