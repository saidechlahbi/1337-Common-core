/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:23:11 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/04 16:59:09 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
        tmp = ft_newnode(ft_atoi(strings[i], head, strings));
        if (!tmp) {
            ft_free_list(head2);
            ft_free_strings(strings);
            return NULL;
        }
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
            ft_free_list(head);
            exit(1);
        }
        head = ft_fill_stackA(head, strings);
        i++;
    }
    repeat_nb(head);
    return head;
}

int main (int ac, char **av)
{
    t_list *stackA, *stackB, *tmp, *tmp2;
    stackA = NULL;
    stackB = NULL;

    if (ac <= 1)
        return 0;
    stackA = manage(ac, av, stackA);
    check_is_sorted(stackA);
    if (ft_list_size(stackA) <= 5)
        one_to_five(&stackA, &stackB);
    else
        radix(&stackA, &stackB);
    ft_free_list(stackA);
    return (0);
}
