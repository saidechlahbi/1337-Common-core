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


int     biger_index(int index)
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

// void    pushing_to_b(t_list **stackA, t_list **stackB, int ssize)
// {
//     t_list *tmp;

//     while (ssize--)
//     {
//         tmp = *stackA;
//         if ((tmp->index >> ssize )& 1)
//             ft_ra(stackA);
//         else
//             ft_pb(stackA, stackB);
//        // tmp->index = tmp->index >> 1;
//     }
// }

// void radix(t_list **stackA, t_list **stackB)
// {
//     int bits;
//     int ssize;
//     int a;

//     a = 0;
//     ssize = ft_list_size(*stackA);
//     indexing(*stackA, ft_list_size(*stackA));
//     bits = biger_index(ft_list_size(*stackA) - 1);
//     while (a < bits)
//     {
//         while(ssize--)
//         {
//             if ((tmp->index >> bits )& 1)
//              ft_ra(stackA);
//             else
//              ft_pb(stackA, stackB);
//         }
//             ft_pa(stackA, stackA);
//         a++;
//     }4908 -9886 6533 4952 -7641 -3973 -1996 -3060 -8903 -9212 1867 -2684 6746 -228 -6041 -6326 8218 2578 7121 8534 -3591 -3620 2241 6901 5419 162 6353 4158 648 -1147 6507 2463 868 254 -8368 8302 -648 3309 -9541 9681 5312 4005 -7504 3136 -7562 9900 -6476 -1182 -3302 -8605 -5874 5783 6572 -5610 -3776 6399 163 7726 -6532 2773 8414 -2301 -1984 6669 1593 7829 5443 -4833 -4457 -1316 -3320 -1719 -6530 -9162 -7195 6688 8568 2249 -7223 -7885 -5509 -6023 4125 -3475 -3587 5955 -3277 -8141 -1029 -3673 7171 9004 -9396 -5948 -553 -1974 -9416 9869 1589 2534
// }
void	radix(t_list **heada, t_list **headb)
{
	int	bits;
	int	bit;
	int	count;

	bits = biger_index(ft_list_size(*heada));
	bit = 0;
	while (bit < bits)
	{
		count = ft_list_size(*heada);
		while (count--)
		{
			if (((*heada)->index >> bit) & 1)
				ft_ra(heada);
			else
				ft_pb(heada, headb);
		}
		while (*headb)
			ft_pa(heada, headb);
		bit++;
	}
}

