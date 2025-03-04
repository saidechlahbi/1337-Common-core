#include "push_swap.h"

static int ft_count_word(char *str)
{
    int     count;

    count = 0;
    while (*str)
    {
        while (*str && (*str == ' ' || *str == '\t'))
            str++;
        if (*str == '\0')
            return (count);
        while (*str && *str != ' ' && *str != '\t')
            str++;
        count++;
    }
    return (count);
}

static char *ft_fill(char *str, char sep)
{
    char* string;
    int i;

    i = 0;
    while (str[i] && str[i] != ' ')
        i++;
    string = malloc (i + 1);
    if (!string)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != ' ')
    {
        string[i] = str[i];
        i++;
    }
    string[i] = '\0';
    return (string);
}

static void ft_free(char **strings, int i)
{
    while (--i >= 0)
        free(strings[i]);
    free(strings);
    strings = NULL;
}

char **ft_splite(char *str, char sep)
{
    char **strings;
    int size;
    int i;

    i = 0;
    size = ft_count_word(str);
    if (size == 0 || !str)
        return (NULL);
    strings = malloc (sizeof(char *) * (size + 1));
    if (!strings)
        return (NULL);
    while (*str)
    {
        while (*str && *str == ' ')
            str++;
        if (*str == '\0')
            return (strings[i] = NULL, strings);
        strings[i] = ft_fill(str, sep);
        if (!strings[i])
            return (ft_free(strings, i),NULL);
        while (*str && *str != ' ')
            str++;
        i++;
    }
    return (strings[i] = NULL, strings);
}
