#include "push_swap.h"
void ft_putstr(char *str)
{
    while (*str)
        write (1, str++, 1);
}

void out(t_list *stackA, char **strings)
{
    ft_putstr("Error\n");
    ft_free_list(stackA);
    ft_free_strings(strings);
    exit(1);
}

int ft_atoi(char *str, t_list *stackA, char **strings)
{
    int signe;
    long result;

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
    if (*str < '0' || *str > '9')
        out(stackA, strings);
    while(*str && (*str >= '0' && *str <= '9'))
    {
        result = (10 * result) + (*str - 48) ;
        str++;
        if (result * signe > 2147483647 || result * signe < -2147483648)
            out(stackA, strings);
    }
    if (*str)
        out(stackA, strings);
    return ((int)result * signe);
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