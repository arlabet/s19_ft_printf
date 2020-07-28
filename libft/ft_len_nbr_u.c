/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_nbr_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 18:53:24 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/28 03:44:14 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len_nbr_u(unsigned int nbr, unsigned int base)
{
	int			i;

	i = 0;

	if (nbr < 0)
	{
		i = 1;
		nbr = nbr * -1;
	}
	while (nbr >= base)
	{
		nbr = nbr / base;
		i++;
	}
	return (i + 1);
}