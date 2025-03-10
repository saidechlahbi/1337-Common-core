/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:07:15 by sechlahb          #+#    #+#             */
/*   Updated: 2024/11/02 23:14:34 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	littlelen;
	size_t	i;

	littlelen = ft_strlen(little);
	if (littlelen == 0)
		return ((char *)big);
	if (len < littlelen)
		return (NULL);
	i = 0;
	while (big[i] && i <= len - littlelen)
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(&big[i], little, littlelen) == 0)
				return ((char *)(&big[i]));
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
//     char str[] = "hello world";
//     printf("%s\n",ft_strnstr(str, "o",0));
// }