#include "push_swap.h"

void ft_free_strings(char **strings)
{
    while (*strings)
    {
        free(*strings);
        *(strings++);
    }
    free(*strings);
//    *strings = NULL;
}

void ft_free_list(t_list *head)
{
    t_list *tmp;

    if (!head)
        return ;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

