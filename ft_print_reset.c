/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:42:57 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/25 02:29:53 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset(void)
{
	g_width = 0;
	g_prec = -1;
	g_p = NULL;
	g_w = NULL;
	g_len = 0;
}

int	ft_len_pointer(size_t nbr)
{
	long int n;
	int i;
	
	n = nbr;
	i = 0;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return(i + 1);
}