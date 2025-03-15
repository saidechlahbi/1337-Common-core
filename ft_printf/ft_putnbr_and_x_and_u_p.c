/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_and_x_and_u_p.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:01:19 by sechlahb          #+#    #+#             */
/*   Updated: 2024/12/14 09:53:07 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned(n / 10);
	c = (n % 10) + '0';
	count += ft_putchar(c);
	return (count);
}

int	ft_putnbr_baze_16(unsigned int n, char c)
{
	int		count;
	char	*base1;
	char	*base2;
	char	s;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	count = 0;
	if (n > 15)
		count += ft_putnbr_baze_16(n / 16, c);
	if (c == 'x')
		s = base1[n % 16];
	else
		s = base2[n % 16];
	count += ft_putchar(s);
	return (count);
}

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	count += ft_putchar(c);
	return (count);
}

int	ft_void_hexadecimal(unsigned long ptr)
{
	char	s;
	char	*base1;
	int		count;

	count = 0;
	base1 = "0123456789abcdef";
	if (ptr > 15)
		count += ft_void_hexadecimal(ptr / 16);
	s = base1[ptr % 16];
	count += ft_putchar(s);
	return (count);
}

// int main ()
// {
//     int i = ft_putnbr(-54321);
//     printf("\n%d\n",i);
// }