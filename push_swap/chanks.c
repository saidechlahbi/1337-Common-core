#include "push_swap.h"

#include "push_swap.h"

// Find the median value in the stack
int ft_find_median(t_list *stackA, int size) {
    int *arr = malloc(size * sizeof(int));
    t_list *tmp = stackA;
    int i = 0;

    // Copy stack values to an array
    while (tmp) {
        arr[i++] = tmp->data;
        tmp = tmp->next;
    }

    // Sort the array
    for (int j = 0; j < size - 1; j++) {
        for (int k = 0; k < size - j - 1; k++) {
            if (arr[k] > arr[k + 1]) {
                int temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }

    // Find the median
    int median = arr[size / 2];
    free(arr);
    return median;
}

// Determine the size of each chunk
int determine_chunk_size(int size) {
    if (size <= 100)
        return 20; // Smaller chunks for smaller stacks
    else
        return 50; // Larger chunks for bigger stacks
}

// Push chunks to stack B based on the median
void push_chunks(t_list **stackA, t_list **stackB, int median) {
    t_list *tmp = *stackA;
    while (tmp) {
        if (tmp->data <= median) {
            ft_pb(stackA, stackB);
            tmp = *stackA;
        } else {
            ft_ra(stackA);
            tmp = *stackA;
        }
    }
}

// Find the maximum value in stack B
int find_max_in_stack(t_list *stack) {
    int max = stack->data;
    while (stack) {
        if (stack->data > max)
            max = stack->data;
        stack = stack->next;
    }
    return max;
}

// Check if the maximum value is in the top half of stack B
int is_max_in_top_half(t_list *stack, int max) {
    int pos = 0;
    while (stack) {
        if (stack->data == max)
            break;
        pos++;
        stack = stack->next;
    }
    return (pos <= ft_list_size(stack) / 2);
}

// Sort stack B using rotations and pushes
void sort_stack_b(t_list **stackA, t_list **stackB) {
    while (*stackB) {
        int max = find_max_in_stack(*stackB);
        while ((*stackB)->data != max) {
            if (is_max_in_top_half(*stackB, max))
                ft_rb(stackB);
            else
                ft_rrb(stackB);
        }
        ft_pa(stackA, stackB);
    }
}

// Merge stacks A and B efficiently
void merge_stacks(t_list **stackA, t_list **stackB) {
    while (*stackB) {
        ft_pa(stackA, stackB);
    }
}

// Main chunk sort function
void chunk_sort(t_list **stackA, t_list **stackB) {
    int size = ft_list_size(*stackA);
    int chunk_size = determine_chunk_size(size);

    while (*stackA) {
        int median = ft_find_median(*stackA, chunk_size);
        push_chunks(stackA, stackB, median);
    }

    sort_stack_b(stackA, stackB);
    merge_stacks(stackA, stackB);
}