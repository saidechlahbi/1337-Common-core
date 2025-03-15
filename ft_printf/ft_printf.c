/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:12:08 by sechlahb          #+#    #+#             */
/*   Updated: 2024/12/14 11:04:40 by sechlahb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_and_call(const char *str, va_list p)
{
	void	*s;

	if (*str == '%')
		return (ft_putchar('%'));
	else if (*str == 'c')
		return (ft_putchar(va_arg(p, int)));
	else if (*str == 's')
		return (ft_putstr(va_arg(p, char *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(p, int)));
	else if (*str == 'u')
		return (ft_putnbr_unsigned(va_arg(p, int)));
	else if ((*str == 'x') || (*str == 'X'))
		return (ft_putnbr_baze_16(va_arg(p, int), *str));
	else if (*str == 'p')
	{
		s = va_arg(p, void *);
		if (!s)
			return (ft_putstr("(nil)"));
		else
			return (ft_putstr("0x") + ft_void_hexadecimal((unsigned long)s));
	}
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	int		count;
	int		a;

	if (!str)
		return (-1);
	count = 0;
	va_start(p, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			a = ft_check_and_call(str, p);
			if (a == -1)
				return (-1);
			count += a;
		}
		else
			count += ft_putchar(*str);
		str++;
	}
	va_end(p);
	return (count);
}

// int main ()
// {
// 	int i = ft_printf("%s\n", "said 1");
// 	ft_printf("%d\n", i);
// 	int j = printf("%s\n", "said 1");
// 	printf("%d\n", j);
// }
// int main ()
// {
// // char *c = NULL;
// // int a = 332;
// intptr_t s;
// void  *p = NULL;
// s = (intptr_t)p;
// int i = ft_printf("%s %c %d %u %i %X %x %% %p", NULL,  65,2147483647,
// 4294967295, -2147483648, 56789, -5467, 4, NULL);
// printf("\n%d\n", i); ///////////////// sep ////////////////
// int j =   printf("%s %c %d %u %i %X %x %% %p", NULL,  65,2147483647,
// 4294967295, -2147483648, 56789, -5467,4, NULL);
// printf("\n%d\n", j); ///////////////// sep ////////////////
// 	int count = ft_printf("Hello, World!\n");
// int c = printf("Hello, World!\n");
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printf("Character: %c\n", 'A');
// c = printf("Character: %c\n", 'A');
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printf("String: %s\n", "Hello");
// c = printf("String: %s\n", "Hello");
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// int x = 42;
// count = ft_printf("Pointer: %p\n", &x);
// c = printf("Pointer: %p\n", &x);
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printft_printfgned: %u\n", 123456789);
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printf("Hex (lower): %x\n", 255);
// c = printf("Hex (lower): %x\n", 255);
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printf("Hex (upper): %X\n", 255);
// c = printf("Hex (upper): %X\n", 255);
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printf("Percent: %%\n");
// c = printf("Percent: %%\n");
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printf("first name: %s, second name %s\n", "loukmane",
// "serghini");
// c = printf("first name: %s, second name %s\n", "loukmane",
// 		"serghini");
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printf("unisgned decimal: %u\n", 4294967295);
// c = printf("unisgned decimal: %u\n", 4294967295);
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printf("unisgned decimal: %u\n", -65464632);
// c = printf("unisgned decimal: %u\n", -65464632);
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printf("   %");
// c = printf("   %");
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printf(NULL);
// c = printf(NULL);
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printf("Pointer: %p\n", NULL);
// c = printf("Pointer: %p\n", NULL);
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// count = ft_printf("str :%s\n", NULL);
// c = printf("str :%s\n", NULL);
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// printf("//////////////////////////////////// \n");

// count = ft_printf("kjdgsfv % kdkfjgvs \n");
// printf(" \n //////////////////////////////////// \n");
// c = printf("kjdgsfv % kdkfjgvs\n");
// printf("Returned count: %d, Expected count: %d\n\n", count, c);
// return (0);
// }
// 	str++;
// 	if (*str == '%')
// 		count += ft_putchar('%');
// 	else if (*str == 'c')
// 		count += ft_putchar(va_arg(p, int));
// 	else if (*str == 's')
// 		count += ft_putstr(va_arg(p, char *));
// 	else if (*str == 'd' || *str == 'i')
// 		count += ft_putnbr(va_arg(p, int));
// 	else if (*str == 'u')
// 		count += ft_putnbr_unsigned(va_arg(p, int));
// 	else if ((*str == 'x') || (*str == 'X'))
// 		count += ft_putnbr_baze_16(va_arg(p, int), *str);
// 	else if (*str == 'p')
// 	{
// 		count += ft_putstr("0x");
// 		count += ft_void_hexadecimal(va_arg(p, void *));
// 	}
// 	else
// 		return (-1);
// }