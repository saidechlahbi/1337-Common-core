/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:23:11 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/15 16:40:21 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*ft_fill_stacka(t_list *head, char **strings)
{
	int		i;
	t_list	*tmp;
	t_list	*head2;

	i = 0;
	tmp = NULL;
	head2 = NULL;
	while (strings[i])
	{
		tmp = ft_newnode(ft_atoi(strings[i], head, strings));
		if (!tmp)
		{
			ft_free_list(head2);
			ft_free_list(head);
			ft_free_strings(strings);
			return (NULL);
		}
		head2 = ft_addback(head2, tmp);
		i++;
	}
	ft_free_strings(strings);
	if (!head)
		return (head2);
	ft_addback(head, head2);
	return (head);
}

t_list	*manage(int ac, char **av, t_list *head)
{
	int		i;
	char	**strings;

	i = 1;
	strings = NULL;
	ft_check_input(av, ac);
	while (i < ac)
	{
		strings = ft_splite(av[i], ' ');
		if (!strings)
		{
			write(2, "Error\n", 6);
			ft_free_list(head);
			exit(1);
		}
		head = ft_fill_stacka(head, strings);
		i++;
	}
	repeat_nb(head);
	return (head);
}

int	main(int ac, char **av)
{
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	if (ac <= 1)
		return (0);
	stacka = manage(ac, av, stacka);
	check_is_sorted(stacka);
	if (ft_list_size(stacka) <= 20)
		one_to_twenty(&stacka, &stackb);
	else
		radix(&stacka, &stackb);
	ft_free_list(stacka);
	return (0);
}
