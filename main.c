/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:57:58 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/21 01:08:08 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{ 
	
	ft_printf("%.s", "hello");
	printf ("%c", 't');
	printf("%.s", "hello");
	/*system("leaks a.out")*/;
}
