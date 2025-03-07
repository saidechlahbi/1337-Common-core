/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:00:55 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/07 18:05:41 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void position(t_list *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        stack->pos = i++;
        stack = stack->next;
    }
}

