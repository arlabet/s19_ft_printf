/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 00:42:57 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/21 20:13:43 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_reset(void)
{
	/*printf("\nLes Globales :\n");
	printf(" int prec : %d\n char p : %s\n int width : %d\n char w : %s\n", g_prec, g_p, g_width, g_w);
	printf("-----------\n");*/
	g_width = 0;
	g_prec = -1;
	g_p = NULL;
	g_w = NULL;
	g_len = 0;
}