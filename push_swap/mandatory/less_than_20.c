/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_20.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:17:01 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/15 16:09:19 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_is_sorted(t_list *stackA)
{
	t_list	*head;

	head = stackA;
	while (head && head->next)
	{
		if (head->data > head->next->data)
			break ;
		head = head->next;
	}
	head = head->next;
	if (!head)
	{
		ft_free_list(stackA);
		exit(1);
	}
}

void	sort_three(t_list **head)
{
	int	a;
	int	b;
	int	c;

	a = (*head)->data;
	b = (*head)->next->data;
	c = (*head)->next->next->data;
	if (a > b && b < c && a < c)
		ft_sa(head);
	else if (a > b && b > c)
	{
		ft_sa(head);
		ft_rra(head);
	}
	else if (a > b && b < c && a > c)
		ft_ra(head);
	else if (a < b && b > c && a < c)
	{
		ft_sa(head);
		ft_ra(head);
	}
	else if (a < b && b > c && a > c)
		ft_rra(head);
}

int	get_pos(t_list *stackA)
{
	int	how_many;

	how_many = 0;
	while (stackA && stackA->index != 0)
	{
		how_many++;
		stackA = stackA->next;
	}
	return (how_many);
}

void	insertion_sort(t_list **stackA, t_list **stackB)
{
	int	size;
	int	a;
	int	b;

	size = ft_list_size(*stackA);
	while (size > 3)
	{
		indexing(*stackA, ft_list_size(*stackA));
		a = get_pos(*stackA);
		if (a < ft_list_size(*stackA) / 2)
		{
			while (a--)
				ft_ra(stackA);
			ft_pb(stackA, stackB);
		}
		else
		{
			b = ft_list_size(*stackA) - a;
			while (b--)
				ft_rra(stackA);
			ft_pb(stackA, stackB);
		}
		size--;
	}
	sort_three(stackA);
}

void	one_to_twenty(t_list **stackA, t_list **stackB)
{
	indexing(*stackA, ft_list_size(*stackA));
	if (ft_list_size(*stackA) == 2)
		ft_sa(stackA);
	if (ft_list_size(*stackA) == 3)
		sort_three(stackA);
	if (ft_list_size(*stackA) > 3)
	{
		insertion_sort(stackA, stackB);
		while (*stackB)
			ft_pa(stackA, stackB);
	}
}
