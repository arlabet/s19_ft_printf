/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:03:06 by nsahloum          #+#    #+#             */
/*   Updated: 2020/07/01 01:01:14 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

void	ft_print_num(va_list argp);
int		ft_printf(const char *format, ...);
void	ft_print_num_uns(va_list argp);
void	ft_print_hexlow(va_list argp);
void	ft_print_hexup(va_list argp);
void	ft_print_char(va_list argp);
void	ft_print_string(va_list argp);
void	ft_print_pointer(va_list argp);
int		ft_check_type(char c); 
void	*ft_assign_fct(void (*tab_funct[7]) (va_list));
int		ft_space(char *format);
void	ft_print_space(const char *format);

#endif
