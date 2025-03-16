/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:23:11 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/10 20:51:36 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

void				ft_free_list(t_list *head);
void				ft_free_strings(char **strings);

t_list				*ft_fill_stacka(t_list *head, char **strings);
void				ft_check_input(char **av, int ac);
void				repeat_nb(t_list *stackA);
char				**ft_splite(char *str, char sep);

int					ft_atoi(char *str, t_list *stackA, char **strings);
t_list				*ft_newnode(int a);
t_list				*ft_addback(t_list *lst, t_list *node);
void				ft_putstr(char *str);
int					ft_list_size(t_list *stack);

void				ft_ra(t_list **stackA);
void				ft_rb(t_list **stackB);
void				ft_rr(t_list **stackB, t_list **stackA);

void				ft_rrb(t_list **stackB);
void				ft_rra(t_list **stackA);
void				ft_rrr(t_list **stackB, t_list **stackA);

void				ft_sa(t_list **stackA);
void				ft_sb(t_list **stackA);
void				ft_ss(t_list **stackA, t_list **stackB);
void				ft_pa(t_list **stackA, t_list **stackB);
void				ft_pb(t_list **stackA, t_list **stackB);

void				sort_three(t_list **head);
void				check_is_sorted(t_list *stackA);
void				one_to_twenty(t_list **stackA, t_list **stackB);

void				indexing(t_list *stackA, int size);
void				radix(t_list **stackA, t_list **stackB);

#endif