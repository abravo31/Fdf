/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:24:18 by abravo            #+#    #+#             */
/*   Updated: 2022/05/23 19:30:55 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write (fd, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd (n / 10, fd);
	}
	n = (n % 10) + '0';
	write (fd, &n, 1);
}
/*
int	main(int ac, char **av)
{
	ft_putnbr_fd(atoi(av[1*/
