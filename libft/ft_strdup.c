/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:56:37 by abravo            #+#    #+#             */
/*   Updated: 2022/12/09 22:39:29 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s1;
	size_t	size;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	size = ft_strlen(s);
	s1 = malloc(sizeof(char) * size + 1);
	if (!s1)
		return (0);
	while (s[i])
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

/*int main ()
{
	unsigned int i;
	printf("%s\n", ft_strdup("0"));
	//printf("%u\n", i);
	//printf("%d\n", -328 % 10);
	return (0);
}*/
