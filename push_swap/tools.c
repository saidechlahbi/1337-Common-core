#include "push_swap.h"
void ft_putstr(char *str)
{
    while (*str)
        write (1, str++, 1);
}
int ft_atoi(char *str)
{
    int signe;
    int result;

    signe = 1;
    result = 0;
    while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            signe = -1;
        str++;
    }
    while(*str && (*str >= '0' && *str <= '9'))
    {
        result = (10 * result) + (*str - 48) ;
        str++;
    }
    return (result * signe);
}

t_list *ft_newnode(int a)
{
    t_list *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->data = a;
    node->next = NULL;
    return (node);
}

t_list *ft_addback(t_list *lst, t_list *node)
{
    t_list *current;

    if (!node)
        return (lst);
    if (!lst)
        return (node);
    
    current = lst;
    while (current->next)
        current = current->next;
    current->next = node;
    return (lst);
}

int ft_list_size(t_list *stack)
{
    int count;

    count = 0;
    if (!stack)
        return (0);
    while (stack)
    {
        stack = stack->next;
        count++;
    }
    return (count);
}