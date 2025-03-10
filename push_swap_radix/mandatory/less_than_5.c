/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:17:01 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/07 13:17:01 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_is_sorted(t_list *stackA)
{
    t_list *head;

    head = stackA;
    while(head && head->next)
    {
        if (head->data > head->next->data)
            break;
        head = head->next;
    }
    head = head->next;
    if (!head)
    {
        ft_free_list(stackA);
        exit(1);
    }
}

void sort_three(t_list **head) 
{
    int a, b, c;
    a = (*head)->data;
    b = (*head)->next->data;
    c = (*head)->next->next->data;
    if (a > b && b < c && a < c)
        ft_sa(head);
    else if (a > b && b > c)
    {
        ft_sa(head);
        ft_rra(head);
    }
    else if (a > b && b < c && a > c)
        ft_ra(head);
    else if (a < b && b > c && a < c)
    {
        ft_sa(head);
        ft_ra(head); 
    }
    else if (a < b && b > c && a > c)
        ft_rra(head);
}


void sort_four(t_list **stackA, t_list **stackB)
{
    while ((*stackA)->index != 0)
        ft_ra(stackA);
    ft_pb(stackA, stackB);
    sort_three(stackA);
    ft_pa(stackA, stackB);
}


void sort_five(t_list **stackA, t_list **stackB)
{
    while ((*stackA)->index != 0 && (*stackA)->index != 1)
        ft_ra(stackA);
    ft_pb(stackA, stackB);
    while ((*stackA)->index != 0 && (*stackA)->index != 1)
        ft_ra(stackA);
    ft_pb(stackA, stackB);
    sort_three(stackA);
    if ((*stackB)->index == 1)
    {
        ft_pa(stackA, stackB);
        ft_pa(stackA, stackB);
    }
    else
    {
        ft_rb(stackB);
        ft_pa(stackA, stackB);
        ft_pa(stackA, stackB);
    }
}

void one_to_five(t_list **stackA, t_list **stackB)
{
    indexing(*stackA, ft_list_size(*stackA));
    if (ft_list_size(*stackA) == 2)
        ft_sa(stackA);
    if (ft_list_size(*stackA) == 3)
        sort_three(stackA);
    if (ft_list_size(*stackA) == 4)
        sort_four(stackA, stackB);
    if (ft_list_size(*stackA) == 5)
        sort_five(stackA, stackB);
}
