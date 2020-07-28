/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:16:31 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/28 20:30:41 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long unsigned int	ft_size_base(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (base[j])
		{
			if (base[j + 1] != '\0' && base[j + 1] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void				ft_putnbr_base_fd(size_t nb, char *base, int fd)
{
	long unsigned int nbr;

	nbr = nb;
	if (ft_size_base(base) == 0)
	{
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	if (nbr >= ft_size_base(base))
		ft_putnbr_base_fd((nbr / ft_size_base(base)), base, fd);
	ft_putchar_fd(base[nbr % ft_size_base(base)], fd);

}
