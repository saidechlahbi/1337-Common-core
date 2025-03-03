#include "push_swap.h"

void ft_sa(t_list **stackA)
{
    t_list *tmp;

    if (!stackA || !(*stackA) || !(*stackA)->next)
        return ;
    tmp = (*stackA)->next;
    (*stackA)->next = (*stackA)->next->next;
    tmp->next = *stackA;
    *stackA = tmp;
    ft_putstr("sa\n");
}

void ft_sb(t_list **stackB)
{
    t_list *tmp;

    if (!stackB || !(*stackB) || !(*stackB)->next)
        return ;
    tmp = (*stackB)->next;
    (*stackB)->next = (*stackB)->next->next;
    tmp->next = *stackB;
    *stackB = tmp;
    ft_putstr("sb\n");
}

void ft_ss(t_list **stackA, t_list **stackB)
{
    ft_sa(stackA);
    ft_sb(stackB);
    ft_putstr("ss\n");
}

void ft_pa(t_list **stackA, t_list **stackB)
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
    ft_putstr("pa\n");
}

void ft_pb(t_list **stackA, t_list **stackB)
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
    ft_putstr("pb\n");   
}

