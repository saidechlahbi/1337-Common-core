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

void	ft_rra(t_list **stackA)
{
	t_list	*tmp;
	t_list	*m;

	if (!stackA || !(*stackA) || (*stackA)->next == NULL)
		return ;
	tmp = *stackA;
	while (tmp->next->next)
		tmp = tmp->next;
	m = tmp->next;
	tmp->next = NULL;
	m->next = *stackA;
	*stackA = m;
	ft_putstr("rra\n");
}

void	ft_rrb(t_list **stackB)
{
	t_list	*tmp;
	t_list	*m;

	if (!stackB || !(*stackB) || (*stackB)->next == NULL)
		return ;
	tmp = *stackB;
	while (tmp->next->next)
		tmp = tmp->next;
	m = tmp->next;
	tmp->next = NULL;
	m->next = *stackB;
	*stackB = m;
	ft_putstr("rrb\n");
}

void	ft_rrr(t_list **stackB, t_list **stackA)
{
	t_list	*tmp;
	t_list	*m;

	if (!stackA || !(*stackA) || (*stackA)->next == NULL)
		return ;
	tmp = *stackA;
	while (tmp->next->next)
		tmp = tmp->next;
	m = tmp->next;
	tmp->next = NULL;
	m->next = *stackA;
	*stackA = m;
	if (!stackB || !(*stackB) || (*stackB)->next == NULL)
		return ;
	tmp = *stackB;
	while (tmp->next->next)
		tmp = tmp->next;
	m = tmp->next;
	tmp->next = NULL;
	m->next = *stackB;
	*stackB = m;
	ft_putstr("rrr\n");
}
