/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:49:48 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/01 18:50:46 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_abs (int nbr)
{
	if (nbr < 0)
		return (-1 * nbr);
	else
		return nbr;
}