/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:03:06 by nsahloum          #+#    #+#             */
/*   Updated: 2020/03/10 14:41:19 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

int		apply_type(char format, va_list argp);
int		check_type(char format);
int		check_format(const char *format, va_list argp);
int		ft_printf(const char *format, ...);
void	ft_print_char(int car);
void	ft_print_string(char *str);
void	ft_print_pointer(size_t p);
void	ft_print_num(int nbr);
void	ft_print_num_uns(unsigned int nbr);
void	ft_print_hexlow(unsigned int nbr);
void	ft_print_hexup(unsigned int nbr);

#endif
