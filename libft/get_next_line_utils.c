/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:46:10 by abravo            #+#    #+#             */
/*   Updated: 2022/12/09 22:39:29 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0' && (char)c != s[i])
		i++;
	if ((char)c == s[i])
		return ((char *)(s + i));
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
