#include "push_swap.h"

int ft_find_median(t_list *stackA, int size)
{
    int *tab = malloc(size * sizeof(int));
    if (!tab)
        return 0;

    int i = 0;
    t_list *temp = stackA;
    while (temp && i < size)
    {
        tab[i] = temp->data;
        temp = temp->next;
        i++;
    }

    for (int j = 0; j < size - 1; j++)
    {
        for (int k = 0; k < size - j - 1; k++)
        {
            if (tab[k] > tab[k + 1])
            {
                int swap = tab[k];
                tab[k] = tab[k + 1];
                tab[k + 1] = swap;
            }
        }
    }

    int median = tab[size / 2];
    free(tab);
    return median;
}

int determine_chunk_size(int size)
{
    if (size <= 50)
        return (size / 3);
    else if (size <= 100)
        return (size / 5);
    else
        return (size / 10);
}

void push_chunks(t_list **stackA, t_list **stackB, int median)
{
    int operations = 0;
    int pushed_count = 0;
    int size = ft_list_size(*stackA);

    while (*stackA && operations < size)
    {
        if ((*stackA)->data < median)
        {
            ft_pb(stackA, stackB);
            pushed_count++;
        }
        else
        {
            ft_ra(stackA);
            operations++;
        }
    }
}

int find_max_in_stack(t_list *stack)
{
    if (!stack)
        return 0;

    int max = stack->data;
    while (stack)
    {
        if (stack->data > max)
            max = stack->data;
        stack = stack->next;
    }
    return max;
}

int is_max_in_top_half(t_list *stack, int max)
{
    if (!stack)
        return 0;

    int size = ft_list_size(stack);
    int count = 0;

    while (stack && count < size / 2)
    {
        if (stack->data == max)
            return 1;
        stack = stack->next;
        count++;
    }
    return 0;
}

void sort_stack_b(t_list **stackA, t_list **stackB)
{
    while (*stackB)
    {
        int max = find_max_in_stack(*stackB);

        while ((*stackB)->data != max)
        {
            if (is_max_in_top_half(*stackB, max))
                ft_rb(stackB);
            else
                ft_rrb(stackB);
        }

        ft_pa(stackA, stackB);
    }
}

void merge_stacks(t_list **stackA, t_list **stackB)
{
    while (*stackB)
        ft_pa(stackA, stackB);
}

void efficient_merge(t_list **stackA, t_list **stackB)
{
    while (*stackB)
        ft_pa(stackA, stackB);
}

void chunk_sort(t_list **stackA, t_list **stackB)
{
    int size = ft_list_size(*stackA);

    if (size <= 3)
    {
        if (size == 2 && (*stackA)->data > (*stackA)->next->data)
            ft_sa(stackA);
        return;
    }

    int median = ft_find_median(*stackA, size);
    push_chunks(stackA, stackB, median);
    sort_stack_b(stackA, stackB);
    merge_stacks(stackA, stackB);
}
