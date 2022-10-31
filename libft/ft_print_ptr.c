/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:33:17 by abravo            #+#    #+#             */
/*   Updated: 2022/06/01 18:56:09 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(unsigned long int n, const char *ptr)
{
	int		len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putptr(n / 16, ptr);
	}
	len += ft_putchar(ptr[n % 16]);
	return (len);
}

int	ft_print_ptr(unsigned long int n, const char *ptr)
{
	int	len;

	if (!n)
		return (ft_putstr(PTR_NULL));
	len = 0;
	len += ft_putstr("0x");
	len += ft_putptr(n, ptr);
	return (len);
}
