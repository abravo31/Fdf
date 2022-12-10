/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:46:13 by abravo            #+#    #+#             */
/*   Updated: 2022/12/10 23:10:01 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static	int	ft_len_words(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		return (i);
	}
	return (0);
}

static char	**ft_free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

static char	**ft_tabline(char const *s, char c, char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			tab[j] = ft_substr(s, i, ft_len_words(s + i, c));
			if (tab[j] == NULL)
				return (ft_free_all(tab));
			j++;
		}
		i += ft_len_words(s + i, c);
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * ((ft_count_words(s, c)) + 1));
	if (tab == NULL)
		return (NULL);
	tab = ft_tabline(s, c, tab);
	return (tab);
}
