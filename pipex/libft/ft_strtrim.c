/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:00:29 by sechlahb          #+#    #+#             */
/*   Updated: 2024/10/28 15:00:29 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

static int	ft_triming_in_beginning(char const *s1, char const *set)
{
	int	start;
	int	j;

	start = 0;
	while (s1[start])
	{
		j = 0;
		while (set[j] && s1[start] != set[j])
			j++;
		if (set[j])
			start++;
		if (set[j] == '\0')
			break ;
	}
	return (start);
}

static	int	ft_triming_in_end(char const *s1, char const *set)
{
	int	end;
	int	j;

	end = 0;
	while (s1[end])
		end++;
	end--;
	while (end > 0)
	{
		j = 0;
		while (set[j] && s1[end] != set[j])
			j++;
		if (set[j])
			end--;
		if (set[j] == '\0')
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		j;

	if (!s1)
		return (NULL);
	start = ft_triming_in_beginning(s1, set);
	end = ft_triming_in_end(s1, set);
	if (end < start)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc((end - start + 1) + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (start <= end)
		str[j++] = s1[start++];
	str[j] = '\0';
	return (str);
}

// int main ()
// {
// 	printf("%s\n",ft_strtrim("    yw6whh    "," "));
// }