/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:59:22 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/24 23:44:05 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int nbr;

	nbr = n;
	if (fd >= 0 && fd < OPEN_MAX)
	{
		if (nbr < 0)
		{
			ft_putchar_fd('-', fd);
			nbr = (nbr * -1);
		}
		if (nbr >= 10)
			ft_putnbr_fd((nbr / 10), fd);
		ft_putchar_fd(((nbr % 10) + 48), fd);
	}
}
