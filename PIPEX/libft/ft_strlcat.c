/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:12:59 by sechlahb          #+#    #+#             */
/*   Updated: 2024/10/27 15:36:23 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	destlen = ft_strlen((const char *)dest);
	srclen = ft_strlen(src);
	if (n <= destlen)
		return (srclen + n);
	i = 0;
	while (src[i] && (destlen + i) < n - 1)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (srclen + destlen);
}

// int main ()
// {
// 	char    str[20] = "hello world";;
// 	printf("%d\n",strlcat(str, "",13));
// 	printf("%s\n",str);
// }