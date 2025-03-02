/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:53:40 by sechlahb          #+#    #+#             */
/*   Updated: 2024/10/28 19:49:09 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned char n)
{
	unsigned char			*str;

	str = s;
	while (n-- > 0)
	{
		*str = 0;
		str++;
	}
}

// int main ()
// {
// 	int i = 0;
// 	int str[5] = {1,4,5,3,6};
// 	bzero(str, sizeof(str));
// 	while (i < 5)
// 	{
// 		str[i] += '0';
// 		write(1,&str[i],1);
// 		i++;
// 	}
// 	printf("\n");
// }