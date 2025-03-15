/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:07:16 by sechlahb          #+#    #+#             */
/*   Updated: 2024/11/02 13:43:16 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(char const *str, char c)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}

static int	count_lenth(char const *str, char c)
{
	int	i;

	i = 0;
	while (*str && *str == (const char)c)
		str++;
	while (*str && *str != (const char)c)
	{
		str++;
		i++;
	}
	return (i);
}

static void	free_strings(char **strings, int i)
{
	while (--i >= 0)
		free(strings[i]);
	free(strings);
}

static char	*malloc_word(const char *s, char c, char **strings, int i)
{
	char	*word;
	int		len;
	int		j;

	len = count_lenth(s, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		free_strings(strings, i);
		return (NULL);
	}
	j = 0;
	while (*s && *s != c)
	{
		word[j] = *s;
		j++;
		s++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = count_strings(s, c);
	strings = malloc(sizeof(char *) * (len + 1));
	if (!strings)
		return (NULL);
	i = -1;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && ++i >= 0)
		{
			strings[i] = malloc_word(s, c, strings, i);
			if (!strings[i])
				return (NULL);
			while (*s && *s != c)
				s++;
		}
	}
	return (strings[i + 1] = NULL, strings);
}

// int main ()
// {
// 	int i = 0;
// 	// char const *s = " ahello a  worldhal";
// 	// printf("%d\n",count_strings(s,'a'));
//     // printf("%d\n",count_lenth(s+6,'a'));
//     char **str = ft_split(" hello world halaa ",' ');
//     while (str[i] != NULL)
//     {
//         printf("%s\n",str[i]);
// 		free(str[i]);
//         i++;   
//     }
//     free(str);
// }