/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_prints_dux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:38:59 by nsahloum          #+#    #+#             */
/*   Updated: 2020/03/10 14:48:45 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num(int nbr)
{
	ft_putnbr_fd(nbr, 1);
}

void	ft_print_num_uns(unsigned int nbr)
{
	ft_putnbr_u_fd(nbr, 1);
}

void	ft_print_hexlow(unsigned int nbr)
{
	ft_putnbr_base_fd(nbr, "0123456789abcdef", 1);
}

void	ft_print_hexup(unsigned int nbr)
{
	ft_putnbr_base_fd(nbr, "0123456789ABCDEF", 1);
}
