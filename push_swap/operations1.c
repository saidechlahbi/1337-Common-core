#include "push_swap.h"

void ft_ra(t_list **stackA)
{
    t_list *tmp;
    t_list *p;

    if (!stackA || !(*stackA) || (*stackA)->next == NULL)
        return ;
    tmp = *stackA;
    *stackA = (*stackA)->next;
    tmp->next = NULL;
    p = *stackA;
    while (p->next)
        p = p->next;
    p->next = tmp;
    ft_putstr("ra\n");
}
void ft_rb(t_list **stackB)
{
    t_list *tmp;
    t_list *p;

    if (!stackB || !(*stackB) || (*stackB)->next == NULL)
        return ;
    tmp = *stackB;
    tmp->next = NULL;
    *stackB = (*stackB)->next;
    p = *stackB;
    while (p->next)
        p = p->next;
    p->next = tmp;
    ft_putstr("rb\n");
}

void ft_rr(t_list **stackB, t_list **stackA)
{
    ft_ra(stackA);
    ft_rb(stackB);
    ft_putstr("rr\n");
}

