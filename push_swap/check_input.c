#include "push_swap.h"

void get_out(char *str)
{
    ft_putstr(str);
    exit(1);
}
void ft_check_input(char **av, int ac)
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
                    get_out("error\n");
            }
            i++;
        }
        if (av[j][i] != '\0')
            get_out("error\n");
       j++;
    }
}
