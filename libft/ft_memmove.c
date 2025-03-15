/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:27:00 by sechlahb          #+#    #+#             */
/*   Updated: 2024/11/02 23:13:39 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return ((void *)dest);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	int *s;
//     char str[] = "abcdefgh";
// 	char ss[] = "ahmed";
// 	int buffer[] = {256,2,3,4,5,6,7,8,3245};
//     printf("%s\n",(char *)ft_memmove(str + 2, ss  , 3));
// 	int i = 0;
// 	s = (int *)ft_memmove(buffer + 2, buffer , 2);
// 	while(i < 7)
// 	{
// 	    printf("%d\t",s[i]);
// 		i++; 
// 	}
// 	printf("\n");

// }