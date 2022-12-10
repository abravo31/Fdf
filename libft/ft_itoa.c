/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:09:31 by abravo            #+#    #+#             */
/*   Updated: 2022/12/09 22:39:29 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_c(int n)
{
	int	c;

	c = 0;
	if (n < 0)
		c++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*nb;
	int		i;
	int		sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
	}
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_count_c (n);
	nb = (char *)malloc(sizeof(char) * (i + 1));
	if (!nb)
		return (NULL);
	nb[0] = '-';
	nb[i] = '\0';
	while (--i >= 0 && n != 0)
	{
		nb[i] = (n % 10) * sign + '0';
		n = n / 10;
	}
	return (nb);
}

/*int main ()
{
	unsigned int i;
	char *res =  ft_itoa(543000);
	printf("%s\n", res);
	//printf("%u\n", i);
	//printf("%d\n", -328 % 10);
	return (0);
}*/
