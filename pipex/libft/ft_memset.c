/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:02:46 by sechlahb          #+#    #+#             */
/*   Updated: 2024/10/25 11:16:38 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return ((void *)s);
}

// #include <string.h>
// #include <stdio.h>
// int main ()
// {
//     char str[] = "abcdefghij";
//     //printf("%s\n",memset(str,'\0',2));
//     printf("%s\n",ft_memset(str,'\0',2));

// }