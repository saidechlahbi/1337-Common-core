/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:59:41 by sechlahb          #+#    #+#             */
/*   Updated: 2024/10/28 14:59:41 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digit(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		lenght;
	char	*str;
	long	p;

	p = n;
	lenght = count_digit(p);
	str = (char *)malloc (lenght + 1);
	if (!str)
		return (NULL);
	str[lenght] = '\0';
	if (n == 0)
		return (str[0] = '0', str);
	if (p < 0)
	{
		str[0] = '-';
		p = -p;
	}
	lenght--;
	while (p)
	{
		str[lenght--] = (p % 10) + '0';
		p = p / 10;
	}
	return (str);
}

// int main ()
// {
// 	printf("%d\n",count_digit(2147483647));
// 	printf("%s\n",ft_itoa(0));
// }