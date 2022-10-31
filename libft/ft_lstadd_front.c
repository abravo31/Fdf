/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:20:06 by abravo            #+#    #+#             */
/*   Updated: 2022/05/25 18:52:48 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*void	ft_printlist(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		printf("lst[%d]:\t%s\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list *lst;
	t_list *current;
	int		i;

	i = 2;
	lst = ft_lstnew(av[1]);
	current = lst;
	while (i < ac)
	{
		current->next = ft_lstnew(av[i]);
		current = current->next;
		i++;
	}
	ft_printlist(lst);
	ft_lstadd_front(&lst, ft_lstnew("newwwwwww"));
	printf("\n");
	ft_printlist(lst);
	return (0);
}*/
