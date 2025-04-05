/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechlahb <sechlahb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:12:08 by sechlahb          #+#    #+#             */
/*   Updated: 2025/03/19 01:56:34 by sechlahb         ###   ########.fr       */
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
