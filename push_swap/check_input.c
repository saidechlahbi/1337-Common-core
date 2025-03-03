#include "push_swap.h"

int ft_check_input(char **av, int ac)
{
    int i;
    int j;

    j = 1;
    while (j < ac)
    {
        i = 0;
        while (av[j][i] && ((av[j][i] >= '0' && av[j][i] <= '9') 
            || (av[j][i] == ' ' || av[j][i] == '\t') 
            || (av[j][i] == '-' || av[j][i] == '+')))
        {
            if (av[j][i] == '-' || av[j][i] == '+')
            {
                if (av[j][i+1] == '-' || av[j][i+1] == '+')
                    return (0);
            }
            i++;
        }
        if (av[j][i] != '\0')
            return (0);
       j++;

    }
    return (1);
}