/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:02:26 by abravo            #+#    #+#             */
/*   Updated: 2022/05/18 11:50:39 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && (char)c != s[i])
		i++;
	if ((char)c == s[i])
		return ((char *)(s + i));
	return (0);
}

/*int	main()
{
	char	s[] = "tripouille";
	printf("%s", ft_strchr((const char *)s, 116 + 256));
	return (0);
}*/
