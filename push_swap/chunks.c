#include "push_swap.h"

int ft_find_median(t_list *stackA, int size)
{
    int *tab = malloc(size * sizeof(int));
    int i = 0;
    t_list *temp = stackA;

    // Copy stack values to array
    while (temp && i < size)
    {
        tab[i] = temp->data;
        temp = temp->next;
        i++;
    }

    // Bubble sort
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

    // Find median
    int median = tab[size / 2];
    free(tab);
    return median;
}

int determine_chunk_size(int size)
{
    if (size <= 50)
        return (size / 3);
    else if (size <=100)
        return (size / 5);
    else
        return (size / 10);
}


void push_chunks(t_list **stackA, t_list **stackB, int median)
{
    int operations = 0;
    int pushed_count = 0;

    while (*stackA)
    {
        if ((*stackA)->data < median)
        {
            ft_pb(stackA, stackB);  // Push to B if less than median
            pushed_count++;
        }
        else
        {
            ft_ra(stackA);  // Rotate if above median
            operations++;
        }

        // Prevent infinite rotation
        if (operations > ft_list_size(*stackA))
            break;
    }
}
int find_max_in_stack(t_list *stack)
{
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
    int size = ft_list_size(stack);
    int count = 0;
    
    while (stack && count < size/2)
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
    // Basic sorting logic for stack B
    while (*stackB)
    {
        // Find max element in B
        int max = find_max_in_stack(*stackB);
        
        // Rotate to bring max to top
        while ((*stackB)->data != max)
        {
            if (is_max_in_top_half(*stackB, max))
                ft_rb(stackB);  // Rotate down
            else
                ft_rrb(stackB);  // Rotate up
        }
        
        // Push max back to A
        ft_pa(stackA, stackB);
    }
}

void merge_stacks(t_list **stackA, t_list **stackB)
{
    // Simple push back all elements from B to A
    while (*stackB)
        ft_pa(stackA, stackB);
}

// Alternative optimized version
void efficient_merge(t_list **stackA, t_list **stackB)
{
    // Merge elements in sorted order
    while (*stackB)
    {
        // Optional: Additional sorting logic if needed
        ft_pa(stackA, stackB);
    }
}
void chunk_sort(t_list **stackA, t_list **stackB)
{
    int median = ft_find_median(*stackA, ft_list_size(*stackA));
    int chunk_size = determine_chunk_size(ft_list_size(*stackA));
    
    push_chunks(stackA, stackB, median);
    sort_stack_b(stackA, stackB);
    merge_stacks(stackA, stackB);
}