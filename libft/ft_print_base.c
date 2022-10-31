/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:01:27 by abravo            #+#    #+#             */
/*   Updated: 2022/06/01 18:59:23 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_base(unsigned int n, const char *str, int base)
{
	int	len;

	len = 0;
	if (n >= (unsigned int) base)
		len += ft_print_base(n / base, str, base);
	len += ft_putchar(str[n % base]);
	return (len);
}
