/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:07:47 by sechlahb          #+#    #+#             */
/*   Updated: 2024/10/31 20:11:50 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// #include <string.h>
// #include <stdio.h>
// int main()
// {
//     char s[] = "1èbcdefg";
//     char d[] = "è123456";
//     printf("%d\n",strncmp(s,d,1));
//     printf("%d\n",ft_strncmp(s,d,1));
// }