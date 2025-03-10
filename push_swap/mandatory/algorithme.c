/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:35:15 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/09 23:06:06 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *return_tab(t_list *stackA, int size)
{
    int(*tab), i;

    i = 0;
    tab = malloc(sizeof(int) * (size + 1));
    if (!tab)
    {
        ft_free_list(stackA);
        exit(1);
    }
    while (stackA)
    {
        tab[i++] = stackA->data;
        stackA = stackA->next;
    }
    return tab;
}

static int *sort_array(t_list *stackA, int size)
{
    int(i), (j), (k), (*tab);

    tab = return_tab(stackA, ft_list_size(stackA));
    i = -1;
    while (i++ < size - 1)
    {
        j = i;
        while (j++ < size - 1)
        {
            if (tab[i] > tab[j])
            {
                k = tab[i];
                tab[i] = tab[j];
                tab[j] = k;
            }
        }
    }
    return tab;
}

static t_list *ft_serch(t_list *stackA, int a)
{

    if (!stackA)
        return NULL;
    while (stackA && stackA->data != a)
        stackA = stackA->next;
    return stackA;
}
void indexing(t_list *stackA, int size)
{
    int i, (*tab), middle;
    t_list *tmp;

    tab = sort_array(stackA, size);
    i = 0;
    while (i < size)
    {
        tmp = ft_serch(stackA, tab[i]);
        tmp->index = i;
        i++;
    }
    return (free(tab));
}

void push_using_middle(t_list **stackA, t_list **stackB, int size)
{
    int (i), (middle);
    t_list *tmp;

    while (ft_list_size(*stackA) > 3)
    {
        i = 0;
        indexing(*stackA, ft_list_size(*stackA));
        while (*stackA && i < ft_list_size(*stackA))
        {
            if (ft_list_size(*stackA) == 3)
                break;
            tmp = *stackA;
            if (tmp->index < (ft_list_size(*stackA) / 2))
                ft_pb(stackA, stackB);
            else
                ft_ra(stackA);
            i++;
        }
    }
    sort_three(stackA);
}
