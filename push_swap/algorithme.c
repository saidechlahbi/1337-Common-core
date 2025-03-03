#include "push_swap.h"
void chunks(t_list **stackA, t_list **stackB)
{
    int size;

    size = ft_list_size(*stackA);
    if (size < 4)
        chanks_for_three_number(stackA);
    else if (size < 6)
        chanks_for_five_number(stackA, stackB);
    else
        return;
}


void chanks_for_three_number(t_list **stackA)
{
    if ((*stackA)->data < (*stackA)->next->data  
        && (*stackA)->next->data > (*stackA)->next->next->data 
        && (*stackA)->data < (*stackA)->next->next->data)
    {
        ft_sa(stackA);
        ft_ra(stackA);
    }
    else if ((*stackA)->data > (*stackA)->next->data 
        && (*stackA)->next->data < (*stackA)->next->next->data 
        && (*stackA)->data < (*stackA)->next->next->data)
        ft_sa(stackA);
    else if ((*stackA)->data < (*stackA)->next->data  
        && (*stackA)->next->data > (*stackA)->next->next->data 
        && (*stackA)->data > (*stackA)->next->next->data)
        ft_rra(stackA);
    else if ((*stackA)->data > (*stackA)->next->data  
        && (*stackA)->next->data < (*stackA)->next->next->data 
        && (*stackA)->data > (*stackA)->next->next->data)
    {
        ft_rra(stackA);
        ft_rra(stackA);
    }
    else if ((*stackA)->data > (*stackA)->next->data
        && (*stackA)->next->data > (*stackA)->next->next->data 
        && (*stackA)->data > (*stackA)->next->next->data)
    {
        ft_sa(stackA);
        ft_rra(stackA);
    }
    else
        return ;
}

int index_of_lower_element(t_list *stackA)
{
    int a;
    t_list *tmp;
    int index;
    int i;

    index = 1;
    i = 2;
    a = stackA->data;
    tmp = stackA->next;
    while (tmp)
    {
        if (a > tmp->data)
        {
            a = tmp->data;
            index = i;
        }
        i++;
        tmp = tmp->next;
    }
    return index;
}
 static void instruction(t_list **stackA, t_list **stackB)
{
    int index;
    int size;

    size = ft_list_size(*stackA);
    index = index_of_lower_element(*stackA);
    if (size == 5)
    {
        if (index == 1)
            ft_pb(stackA, stackB);
        else if (index == 2)
        {
            ft_sa(stackA);
            ft_pb(stackA, stackB);
        }
        else if (index == 3)
        {
            ft_ra(stackA);
            ft_sa(stackA);
            ft_pb(stackA, stackB);
        }
        else if (index == 4)
        {
            ft_rra(stackA);
            ft_rra(stackA);
            ft_pb(stackA, stackB);
        }
        if (index == 5)
        {
            ft_rra(stackA);
            ft_pb(stackA, stackB);
        }
    }else
    {
        if (index == 1)
            ft_pb(stackA, stackB);
        else if (index == 2)
        {
            ft_sa(stackA);
            ft_pb(stackA, stackB);
        }
        else if (index == 3)
        {
            ft_ra(stackA);
            ft_sa(stackA);
            ft_pb(stackA, stackB);
        }
        else
        {
            ft_rra(stackA);
            ft_pb(stackA, stackB);
        }
    
    }
}
void chanks_for_five_number(t_list **stackA, t_list **stackB)
{
    int size;

    size = ft_list_size(*stackA);
    if (size == 5)
    {
        instruction(stackA, stackB);
        instruction(stackA, stackB);
    }
    else
        instruction(stackA, stackB);
    chanks_for_three_number(stackA);
    ft_pa(stackA, stackB);
    ft_pa(stackA, stackB);
}