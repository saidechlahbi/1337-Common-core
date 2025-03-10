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

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
# include <fcntl.h>


//#define malloc(r) NULL // for malloc failure
typedef struct s_list
{
    int     data;
    int index;
    struct s_list *next;
}       t_list;

///frees ///
void ft_free_list(t_list *head);
void ft_free_strings(char **strings);

////fill from input ///
t_list *ft_fill_stackA(t_list *head, char **strings);
void ft_check_input(char **av, int ac);
void repeat_nb(t_list *stackA);
char **ft_splite(char *str, char sep);

// tools //
int ft_atoi(char *str, t_list *stackA, char **strings);
t_list *ft_newnode(int a);
t_list *ft_addback(t_list *lst, t_list *node);
void ft_putstr(char *str);
int ft_list_size(t_list *stack);


//operations //
void ft_ra(t_list **stackA);
void ft_rb(t_list **stackB);
void ft_rr(t_list **stackB, t_list **stackA);

void ft_rrb(t_list **stackB);
void ft_rra(t_list **stackA);
void ft_rrr(t_list **stackB, t_list **stackA);

void ft_sa(t_list **stackA);
void ft_sb(t_list **stackA);
void ft_ss(t_list **stackA, t_list **stackB);
void ft_pa(t_list **stackA, t_list **stackB);
void ft_pb(t_list **stackA, t_list **stackB);

//// check if sorted 
void sort_three(t_list **head) ;
void check_is_sorted(t_list *stackA);
void one_to_five(t_list **stackA, t_list **stackB);
///algothme/////
void indexing(t_list *stackA, int size);
void radix(t_list **stackA, t_list **stackB);

#endif