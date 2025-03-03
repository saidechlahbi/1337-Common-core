#include "push_swap.h"
#include <time.h>

t_list *ft_fill_stackA(t_list *head, char **strings)
{
    t_list *tmp;
    t_list *head2; 
    int i;

    i = 0;
    tmp = NULL;
    head2 = NULL;
    while (strings[i])
    {
        tmp = ft_newnode(ft_atoi(strings[i]));
        head2 = ft_addback(head2, tmp);
        i++;
    }
    ft_free_strings(strings);
    if (!head)
        return (head2);
    tmp = head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = head2;
    return (head);
}

t_list *manage(int ac, char **av, t_list *head)
{
    int i;
    char **strings;

    i = 1;
    strings = NULL;
    ft_check_input(av, ac);
    while (i < ac)
    {
        strings = ft_splite(av[i], ' ');
        if (!strings)
        {
            ft_putstr("error\n");
            ft_free_list(head);
            exit(1);
        }
        head = ft_fill_stackA(head, strings);
        strings = NULL;
        i++;
    }
    return head;
}

int main (int ac, char **av)
{
    char **strings;

    t_list *stackA, *stackB;
    stackA = NULL;
    stackB = NULL;

    if (ac <= 1)
        return 0;
///// manage the inpute ////
    stackA = manage(ac, av, stackA);
///// printf the result before the sort ////
    t_list *tmp = stackA;
    while (tmp)
    {
        printf("%d--->",tmp->data);
        tmp = tmp->next;
    }
    ft_free_list(stackA);
    printf("\n");

///// the lgorrithme ////
    return (0);
}
