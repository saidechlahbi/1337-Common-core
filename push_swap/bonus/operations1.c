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

void ra(t_list **stackA)
{
    t_list *tmp;
    t_list *p;

    if (!stackA || !(*stackA) || !(*stackA)->next)
        return ;
    tmp = *stackA;
    *stackA = (*stackA)->next;
    tmp->next = NULL;
    p = *stackA;
    while (p->next)
        p = p->next;
    p->next = tmp;
}
void rb(t_list **stackB)
{
    t_list *tmp;
    t_list *p;

    if (!stackB || !(*stackB) || !(*stackB)->next)
        return ;
    tmp = *stackB;
    p = *stackB;
    *stackB = (*stackB)->next;
    tmp->next = NULL;
    while (p->next)
        p = p->next;
    p->next = tmp;
}

void rr(t_list **stackB, t_list **stackA)
{
    t_list *tmp;
    t_list *p;

    if (!stackA || !(*stackA) || !(*stackA)->next)
        return ;
    tmp = *stackA;
    p = *stackA;
    *stackA = tmp->next;
    tmp->next = NULL;
    while (p->next)
        p = p->next;
    p->next = tmp;
    if (!stackB || !(*stackB) || !(*stackB)->next)
        return ;
    tmp = *stackB;
    p = *stackB;
    *stackB = tmp->next;
    tmp->next = NULL;
    while (p->next)
        p = p->next;
    p->next = tmp;
}
