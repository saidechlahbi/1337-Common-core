/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:23:11 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/04 16:59:09 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void sa(t_list **stackA)
{
    t_list *tmp;

    if (!stackA || !(*stackA) || !(*stackA)->next)
        return ;
    tmp = (*stackA)->next;
    (*stackA)->next = (*stackA)->next->next;
    tmp->next = *stackA;
    *stackA = tmp;
}

void sb(t_list **stackB)
{
    t_list *tmp;

    if (!stackB || !(*stackB) || !(*stackB)->next)
        return ;
    tmp = (*stackB)->next;
    (*stackB)->next = (*stackB)->next->next;
    tmp->next = *stackB;
    *stackB = tmp;
}

void ss(t_list **stackA, t_list **stackB)
{
    t_list *tmp;

    if (!stackA || !(*stackA) || !(*stackA)->next)
        return ;
    tmp = (*stackA)->next;
    (*stackA)->next = (*stackA)->next->next;
    tmp->next = *stackA;
    *stackA = tmp;

    if (!stackB || !(*stackB) || !(*stackB)->next)
        return ;
    tmp = (*stackB)->next;
    (*stackB)->next = (*stackB)->next->next;
    tmp->next = *stackB;
    *stackB = tmp;
}

void pa(t_list **stackA, t_list **stackB)
{
    t_list *tmp;

    if (!stackB || !(*stackB))
        return ;
    tmp = *stackB;
    *stackB = (*stackB)->next;
    if (!stackA || !(*stackA))
    {
        *stackA = tmp;
        tmp->next = NULL;
        return ;
    }
    tmp->next = *stackA;
    *stackA = tmp;
}

void pb(t_list **stackA, t_list **stackB)
{
    t_list *tmp;

    if (!stackA || !(*stackA))
        return ;
    tmp = *stackA;
    *stackA = (*stackA)->next;
    if (!stackB || !(*stackB))
    {
        tmp->next = NULL;
        *stackB = tmp;
        return ;
    }
    tmp->next = *stackB;
    *stackB = tmp; 
}

