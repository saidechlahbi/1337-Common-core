/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 13:35:15 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/15 16:16:10 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*return_tab(t_list *stackA, int size)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * (size + 1));
	if (!tab)
	{
		ft_free_list(stackA);
		exit(1);
	}
	while (stackA)
	{
		tab[i++] = stackA->data;
		stackA = stackA->next;
	}
	return (tab);
}

static int	*sort_array(t_list *stackA, int size)
{
	int	i;
	int	j;
	int	*tab;
	int	k;

	tab = return_tab(stackA, ft_list_size(stackA));
	if (!tab)
		return (NULL);
	i = -1;
	while (i++ < size - 1)
	{
		j = i;
		while (j++ < size - 1)
		{
			if (tab[i] > tab[j])
			{
				k = tab[i];
				tab[i] = tab[j];
				tab[j] = k;
			}
		}
	}
	return (tab);
}

static t_list	*ft_serch(t_list *stackA, int a)
{
	if (!stackA)
		return (NULL);
	while (stackA && stackA->data != a)
		stackA = stackA->next;
	return (stackA);
}

void	indexing(t_list *stackA, int size)
{
	int		i;
	int		*tab;
	t_list	*tmp;

	tab = sort_array(stackA, size);
	if (!tab)
	{
		ft_free_list(stackA);
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		tmp = ft_serch(stackA, tab[i]);
		if (tmp)
			tmp->index = i;
		i++;
	}
	free(tab);
}
