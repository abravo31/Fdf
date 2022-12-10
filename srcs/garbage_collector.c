/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abravo <abravo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:09:10 by abravo            #+#    #+#             */
/*   Updated: 2022/12/09 22:40:06 by abravo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static
t_garbage *lst_new_garbage(void *node)
{
    t_garbage *new;
    
    new = malloc(sizeof(t_garbage));
    new->adrr = node;
    new->next = NULL;
    return (new);
}

void *ft_malloc(int len, t_garbage **garbage)
{
    void *new;
    
    new = malloc(len);
    ft_lstadd_back(garbage, lst_new_garbage(new));
    return (new);
}

void ft_free(t_garbage **garbage);
{
    t_garbage *node;

    node = *garbage;
    while (node->next)
    {
        free(node->adrr);
        node->adrr = NULL;
        node = node->next;
    }
    free(*garbage);
}