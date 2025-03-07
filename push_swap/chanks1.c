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
    if (a > b && b < c && a < c) {
        ft_sa(head);
    } else if (a > b && b > c) {
        ft_sa(head);
        ft_rra(head);
    } else if (a > b && b < c && a > c) {
        ft_ra(head);
    } else if (a < b && b > c && a < c) {
        ft_sa(head);
        ft_ra(head); 
    } else if (a < b && b > c && a > c) {
        ft_rra(head);
    }
}


void one_to_three(t_list*lst)
{
    check_is_sorted(lst);
    if (ft_list_size(lst) == 2)
    {
        ft_sa(&lst);
        ft_free_list(lst);
        exit(0);
    }
    if (ft_list_size(lst) == 3)
    {
        sort_three(&lst);
        ft_free_list(lst);
        exit(0);
    }
}