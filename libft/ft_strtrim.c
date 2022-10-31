/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:45:55 by abravo            #+#    #+#             */
/*   Updated: 2022/05/30 13:08:30 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_inset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	ft_size(const char	*s1, const char	*set)
{
	int	start;
	int	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (ft_inset(s1[start], set))
		start++;
	while (ft_inset(s1[end - 1], set))
		end--;
	return (end - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*dest;

	i = 0;
	while (ft_inset(s1[i], set))
		i++;
	dest = ft_substr(s1, i, ft_size(s1, set));
	return (dest);
}

/*int main()
{
	printf("%s\n", ft_strtrim("tripouille   xxx", " x"));
	return (0);
}*/
