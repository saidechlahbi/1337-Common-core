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

static void get_out(char *str)
{
    ft_putstr(str);
    exit(1);
}
void ft_check_input(char **av, int ac)
{
    int i;
    int j;

    j = 1;
    while (j < ac)
    {
        i = 0;
        while (av[j][i] && ((av[j][i] >= '0' && av[j][i] <= '9') 
            || (av[j][i] == ' ' || av[j][i] == '\t') 
            || (av[j][i] == '-' || av[j][i] == '+')))
        {
            if (av[j][i] == '-' || av[j][i] == '+')
            {
                if (av[j][i+1] == '-' || av[j][i+1] == '+')
                    get_out("Error\n");
            }
            i++;
        }
        if (av[j][i] != '\0')
            get_out("Error\n");
       j++;
    }
}

void repeat_nb(t_list *stackA)
{
    t_list (*tmp), (*tmp1);

    tmp = stackA;
    while (tmp)
    {
        tmp1 = tmp->next;
        while (tmp1)
        {
            if (tmp->data == tmp1->data)
            {
                ft_putstr("Error\n");
                ft_free_list(stackA);
                exit(1);
            }
            tmp1 = tmp1->next;
        }
        tmp = tmp->next;
    }
}