/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:23:11 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/09 14:34:57 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}

static void    is_sorted(t_list **stackA, t_list **stackB)
{
    t_list *tmp;

    if (*stackB )
    {
        ft_free_list(*stackA);
        ft_free_list(*stackB);
        write(1,"KO\n", 3);
        exit(0);
    }
    tmp = *stackA;
    while (tmp && tmp->next && tmp->data < tmp->next->data)
        tmp = tmp->next;
    if (!tmp->next)
    {
        ft_free_list(*stackA);
        write (1, "OK\n", 3);
        exit(0);
    }
    else
    {
        ft_free_list(*stackA);
        write (1, "KO\n", 3);
        exit(0);
    }
}

static void opiration (t_list **stackA, t_list **stackB, char *str)
{
    if (ft_strncmp(str, "sa\n", 3) == 0)
        sa(stackA);
    else if (ft_strncmp(str, "sb\n", 3) == 0)
        sb(stackB);
    else if (ft_strncmp(str, "ss\n", 3) == 0)
        ss(stackA, stackB);
    else if (ft_strncmp(str, "ra\n", 3) == 0)
        ra(stackA);
    else if (ft_strncmp(str, "rb\n", 3) == 0)
        rb(stackB);
    else if (ft_strncmp(str, "rr\n", 3) == 0)
        rr(stackA, stackB);
    else if (ft_strncmp(str, "rra\n", 4) == 0)
        rra(stackA);
    else if (ft_strncmp(str, "rrb\n", 4) == 0)
        rrb(stackB);
    else if (ft_strncmp(str, "rrr\n", 4) == 0)
        rrr(stackA, stackB);
    else if (ft_strncmp(str, "pb\n", 3) == 0)
        pa(stackA, stackB);
    else if (ft_strncmp(str, "pb\n", 3) == 0)
        pb(stackB, stackB);
    return ;
}

void checker(t_list **stackA, t_list **stackB)
{
    char *str;

    str = get_next_line(0);
    while (str)
    {
        if (ft_strncmp(str, "sa\n", 3) == 0 || ft_strncmp(str, "sb\n", 3) == 0
        || ft_strncmp(str, "ss\n", 3) == 0 || ft_strncmp(str, "ra\n", 3) == 0
        || ft_strncmp(str, "rb\n", 3) == 0 || ft_strncmp(str, "rr\n", 3) == 0
        || ft_strncmp(str, "rra\n", 4) == 0 || ft_strncmp(str, "rrb\n", 4) == 0
        || ft_strncmp(str, "rrr\n", 4) == 0 || ft_strncmp(str, "pb\n", 3) == 0
        || ft_strncmp(str, "pb\n", 3) == 0)
        {
            printf("hello\n");
            opiration(stackA, stackB, str);
        }
        else
        {
            write(2, "Error\n",6);
            ft_free_list(*stackA);
            ft_free_list(*stackB);
            free(str);
            exit(1);
        }
        free(str);
        str = get_next_line(0);
    }
    is_sorted(stackA, stackB);
}