/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:00:55 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/10 01:50:00 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int     nb_of_bits(int index)
{
    int move;

    move = 0;
    while (index)
    {
        index = index >> 1;
        move++;
    }
    return move;
}

void    pushing_to_b(t_list **stackA, t_list **stackB, int ssize)
{
    t_list *tmp;
	int a;

	a = 0;
    while (a < ssize)
    {
        tmp = *stackA;
		if (!tmp)
			return ;
        if (tmp->index  & 1)
            ft_ra(stackA);
        else
            ft_pb(stackA, stackB);
       tmp->index = tmp->index >> 1;
	   a++;
    }
}

void radix(t_list **stackA, t_list **stackB)
{
    int bits;
    int size;
	t_list *tmp;
    int a;

    a = 0;
    size = ft_list_size(*stackA);
    indexing(*stackA, ft_list_size(*stackA));
	bits = nb_of_bits(ft_list_size(*stackA));
    while (a < bits)
    {
		pushing_to_b(stackA, stackB, size);
		while (*stackB)
            ft_pa(stackA, stackB);
        a++;
    }
}
