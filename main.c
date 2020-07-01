/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:57:58 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/02 00:33:44 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{ 
  ft_printf("%.s", "hello");
  printf("%c", '\n');
  printf("%.s", "hello");
  //printf("ceci est un %");
}
