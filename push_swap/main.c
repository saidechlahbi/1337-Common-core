#include "push_swap.h"
#include <time.h>

t_list *ft_fill_stackA(t_list *head, char **strings)
{
    t_list *tmp;
    t_list *head2; 
    int i;

    i = 0;
    head2 = NULL;
    while (strings[i])
    {
        tmp = ft_newnode(ft_atoi(strings[i]));
        head2 = ft_addback(head2, tmp);
        i++;
    }
    ft_free_strings(strings);
    if (head == NULL)
    {
        head = head2;
        return (head);
    }
    tmp = head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = head2;
    return (head);
}

int main (int ac, char **av)
{
    int i;
    int input;
    char **strings;

    t_list *head, *stackB;
    head = NULL;
    stackB = NULL;
    i = 1;
    if (ac > 1)
    {
        if (ft_check_input(av, ac) == 0)
            return (0);
        else
        {
            while (i < ac)
            {
                strings = ft_splite(av[i], ' ');
                if (!strings)
                    return (0);
                head = ft_fill_stackA(head, strings);
                i++;
            }
        }
    }

    t_list *tmp = head;
    while (tmp)
    {
        printf("%d--->",tmp->data);
        tmp = tmp->next;
    }
    printf("\n\n");
///////////////////////////////////////////////////////////
    //chunks(&head, &stackB);
    chunk_sort(&head, &stackB);
/////////////////////////////////////////////////////////
    printf("\n\n");

    tmp = head;
    while (tmp)
    {
        printf("%d--->",tmp->data);
        tmp = tmp->next;
    }
    printf("\n\n");
    ft_free_list(head);

//    printf("\n%d\n",ft_list_size(head));
    return (0);
}
