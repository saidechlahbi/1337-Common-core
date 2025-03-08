


#include "../push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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

void checker(t_list **stackA, t_list **stackB)
{
    char *str;

    str = get_next_line(0);
    while (!str)
    {
        if (ft_strncmp(str, "sa\n", 3) == 0)
            ft_sa(stackA);
        else if (ft_strncmp(str, "sb\n", 3) == 0)
            ft_sb(stackB);
        else if (ft_strncmp(str, "ss\n", 3) == 0)
            ft_ss(stackA, stackB);
        else if (ft_strncmp(str, "ra\n", 3) == 0)b
            ft_ra(stackA);
        else if (ft_strncmp(str, "rb\n", 3) == 0)
            ft_rb(stackB);
        else if (ft_strncmp(str, "rr\n", 3) == 0)
            ft_rr(stackA, stackB);
        else if (ft_strncmp(str, "rra\n", 4) == 0)
            ft_rra(stackA);
        else if (ft_strncmp(str, "rrb\n", 4) == 0)
            ft_rrb(stackB);
        else if (ft_strncmp(str, "rrr\n", 4) == 0)
            ft_rrr(stackA, stackB);
        else if (ft_strncmp(str, "pb\n", 3) == 0)
            ft_pa(stackA);
        else if (ft_strncmp(str, "pb\n", 3) == 0)
            ft_pb(stackB);
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
}


