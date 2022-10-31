/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:29:34 by abravo            #+#    #+#             */
/*   Updated: 2022/05/18 12:00:08 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned const char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
/*int main ()
{
    int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
    printf ("%p\n", ft_memchr("bonjour", 'b', 4));
    printf ("%p\n", memchr("bonjour", 'b', 4));
	printf ("%s\n", (char *)ft_memchr(tab, -1, 7));
    printf ("%s\n", (char *)memchr(tab, -1, 7));
}*/
