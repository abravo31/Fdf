/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:08:58 by abravo            #+#    #+#             */
/*   Updated: 2022/05/17 19:27:13 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	j = ft_strlen(dst);
	tmp = ft_strlen(dst) + ft_strlen(src);
	if (j <= size && size > 0)
	{
		while (src[i] != '\0' && j < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
		return (tmp);
	}
	else
		return (size + ft_strlen(src));
}

/*int	main()
{
	char	a[14] = "abcdefghijklm";
	char	b[] = "lorem ipsum dolor sit amet";
	char	a1[14] = "abcdefghijklm";
	char	b1[] = "lorem ipsum dolor sit amet";
	printf("ft_strlcat: %ld\n", ft_strlcat(a, b, 15));
	printf("strlcat: %ld\n", strlcat(a1, b1, 15));
	printf("%s\n", a);
	printf("%s\n", a1);
	return (0);
}
int	main ()
{
	char	c [27] = "lorem ipsum dolor sit amet";
	char	d [14] = "ddeeffgghhiij";
	char	c1 [27] = "lorem ipsum dolor sit amet";
	char	d1 [14] = "ddeeffgghhiij";

	printf ("strlcat: %ld\n", strlcat(d, c, 15));
	printf ("%s\n", d);
	printf ("ft_strlcat: %ld\n", ft_strlcat (d1, c1, 15));
	printf ("%s\n", d1);
	return (0);
}*/
