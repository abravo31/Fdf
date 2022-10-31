/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:55:42 by abravo            #+#    #+#             */
/*   Updated: 2022/05/13 17:01:18 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}
/*
#include <bsd/string.h>

int main ()
{
        const char src[] = "aa";
        char dst[] = "ddee";
        const char bsrc[] = "aa";
        char bdst[] = "ddee";
        printf("%ld\n", ft_strlcpy(dst, src, 4));
        printf("%ld\n", strlcpy(bdst, bsrc, 4));
        return 0;
}*/
