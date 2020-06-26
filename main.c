/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 19:57:58 by nsahloum          #+#    #+#             */
/*   Updated: 2020/06/26 23:12:03 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{ 
  ft_printf("%s %10%", "test");
  printf("%c", '\n');
  printf("%s %10%", "test");
  printf("%c", '\n');
  printf("%d", g_w);
  printf("%c", '\n');
  printf("%d", g_wstart);
  return (0);
}
