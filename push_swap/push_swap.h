#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
    int     data;
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

///// tools ///
int ft_atoi(char *str, t_list *stackA, char **strings);
t_list *ft_newnode(int a);
t_list *ft_addback(t_list *lst, t_list *node);
void ft_putstr(char *str);
int ft_list_size(t_list *stack);


//operations ///
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

//algorithme1 ///
int index_of_lower_element(t_list *stackA);
void chanks_for_three_number(t_list **stackA);
void chanks_for_five_number(t_list **stackA, t_list **stackB);
void chunks(t_list **stackA, t_list **stackB);

///the real chunks /// 
int ft_find_median(t_list *stackA, int size);
int determine_chunk_size(int size);
void push_chunks(t_list **stackA, t_list **stackB, int median);
int find_max_in_stack(t_list *stack);
int is_max_in_top_half(t_list *stack, int max);
void sort_stack_b(t_list **stackA, t_list **stackB);
void merge_stacks(t_list **stackA, t_list **stackB);
void efficient_merge(t_list **stackA, t_list **stackB);
void chunk_sort(t_list **stackA, t_list **stackB);

#endif