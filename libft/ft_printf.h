/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:37:11 by abravo            #+#    #+#             */
/*   Updated: 2022/06/01 19:00:16 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

# define HEX_UP "0123456789ABCDEF"
# define HEX_LW "0123456789abcdef"
# define NB "0123456789"
# define PTR_NULL "(nil)"

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_print_ptr(unsigned long int n, const char *ptr);
int	ft_putnbr(int n);
int	ft_print_base(unsigned int n, const char *str, int base);
int	ft_printf(const char *str, ...);

#endif
