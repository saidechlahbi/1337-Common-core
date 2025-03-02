/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:12:47 by sechlahb          #+#    #+#             */
/*   Updated: 2024/10/31 18:21:18 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

// int main ()
// {
//     char *str = "";
//     printf("%s\n",(char *)ft_memchr((char *)str,'i', sizeof(str)));
//     int ss[] = {1,5,3,4,7,8,9};
//     int *s = (int *)ft_memchr((int *)ss,4, sizeof(ss));
//     int  i = 0;
//     while (i < 7)
//     {
//         printf("%d\t",s[i]);
//         i++;
//     }
// }