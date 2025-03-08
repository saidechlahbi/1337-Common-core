/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:00:55 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/07 18:05:41 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void position(t_list *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        stack->pos = i++;
        stack = stack->next;
    }
}



void get_target(t_list **stackA, t_list **stackB)
{
    int position;
    t_list *A, *B, *tmp;

    A = *stackA;
    B = *stackB;
    while (B)
    {
        position = 2147483647;
        while (A)
        {
            if (A->data > B->data && A->data <= position)
            {
                tmp = A;
                position = A->data;
            }
            A = A->next;
        }
        B->target = tmp;
        B = B->next;
    }
}

void costA(t_list *stackA, t_list *stackB)
{
    int sizeA, sizeB;

    sizeA =  ft_list_size(stackA);
    sizeB = ft_list_size(stackB);
    while (stackB)
    {
        if (stackB->pos <=  sizeB / 2)
           stackB->cost = stackB->pos;
        else
           stackB->cost = sizeB - stackB->pos;
        if (stackB->target->pos <=  sizeA / 2)
            stackB->cost += stackB->target->pos;
        else
            stackB->cost += sizeA - stackB->target->pos;
        stackB = stackB->next;
    }
}

t_list *get_cheapest(t_list *stackB)
{
    t_list *tmp;
    int data;

    data  = stackB->cost;
    tmp = stackB;
    while (stackB)
    {
        if (stackB->cost < data)
        {
            data = stackB->cost;
            tmp = stackB;
        }
        stackB = stackB->next;
    }
    return tmp;
}

void move_to_the_top(t_list **stackA, t_list **stackB, t_list *cheapest)
{
    position(*stackA);
    position(*stackB);

    if (cheapest->pos <= (ft_list_size(*stackB) / 2))
    {
        while (*stackB != cheapest)
            ft_rb(stackB);
    }
    else
    {
        while (*stackB != cheapest)
            ft_rrb(stackB);
    }
    if (cheapest->target->pos <= ft_list_size(*stackA) / 2)
    {
        while (*stackA != cheapest->target)
            ft_ra(stackA);
    }
    else
    {
        while (*stackA != cheapest->target)
            ft_rra(stackA);
    }   
}

void swap_both(t_list **stackA, t_list **stackB, t_list *cheapest)
{
    if (cheapest->pos < (ft_list_size(*stackB) / 2) && cheapest->target->pos < ft_list_size(*stackA) / 2)
    {
        while (cheapest != *stackB && cheapest->target != *stackA)
            ft_rr(stackA, stackB);
    }
    else if (cheapest->pos >= ft_list_size(*stackB) / 2 && cheapest->target->pos >= ft_list_size(*stackA) / 2)
    {
        while (cheapest != *stackB && cheapest->target != *stackA)
            ft_rrr(stackA, stackB);
    }
    // move_to_the_top(stackA, stackB,cheapest);
}

void last_sort(t_list **stackA)
{
    t_list *tmp;

    position(*stackA);
    tmp = *stackA;
    while (tmp->index != 0)
        tmp = tmp ->next;
    if (tmp->pos > ft_list_size(*stackA) / 2)
        while (*stackA != tmp)
            ft_rra(stackA);
    else
        while (*stackA != tmp)
            ft_ra(stackA);
}
void turk(t_list **stackA, t_list **stackB)
{
    t_list *cheapest;

    push_using_middle(stackA, stackB, ft_list_size(*stackA));
    while (*stackB)
    {
        position(*stackA);
        position(*stackB);
        get_target(stackA, stackB);
        costA(*stackA, *stackB);
        cheapest = get_cheapest(*stackB);
        swap_both(stackA, stackB, cheapest);
        move_to_the_top(stackA, stackB,cheapest);
        ft_pa(stackA, stackB);
    }
    last_sort(stackA);
}
