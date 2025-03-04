#include "push_swap.h"

void ft_free_strings(char **strings)
{
    int i = 0;
    while (strings[i])
    {
        free(strings[i]);
        i++;
    }
    free(strings);
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

