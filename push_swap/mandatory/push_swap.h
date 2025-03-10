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
    int pos;
    int cost;
    struct s_list *target;
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
void one_to_three(t_list*lst);

///algothme/////
void push_using_middle(t_list **stackA, t_list **stackB, int size);
void position(t_list *stack);
void turk(t_list **stackA, t_list **stackB);
void indexing(t_list *stackA, int size);


////// bonus part //////////////////////////////////////////////////////////////

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_last_rest_of_line(char *str);
char	*get_rest_for_next_line(char *str);
char	*get_next_line(int fd);

// opiration //

void ra(t_list **stackA);
void rb(t_list **stackB);
void rr(t_list **stackB, t_list **stackA);

void rrb(t_list **stackB);
void rra(t_list **stackA);
void rrr(t_list **stackB, t_list **stackA);

void sa(t_list **stackA);
void sb(t_list **stackA);
void ss(t_list **stackA, t_list **stackB);
void pa(t_list **stackA, t_list **stackB);
void pb(t_list **stackA, t_list **stackB);

#endif