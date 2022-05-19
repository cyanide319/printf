/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:11:18 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/05/19 17:53:11 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	return (1);
}

size_t	ft_putnbr_base(char flag, size_t nb, size_t base)
{
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (nb >= base)
		ft_putnbr_base(flag, (nb / base), base);
	if (flag == 'x' || flag == 'p')
		write (1, &B_16L[nb % base], 1);
	else if (flag == 'X')
		write (1, &B_16U[nb % base], 1);
	else
		write (1, &B_10[nb % base], 1);
	return (1);
}

int	check_flags(va_list flag, const char frmt)
{
	size_t	printlen;

	printlen = 0;
	if (frmt == 'c')
		printlen += ft_putchar(va_arg(flag, int));
	else if (frmt == 's')
		printlen += ft_putstr(va_arg(flag, char *));
	else if (frmt == '%')
		printlen += write(1, "%", 1);
	else if (frmt == 'd')
		printlen += ft_putnbr_base(frmt, va_arg(flag, size_t), 10);
	else if (frmt == 'p')
	{
		printlen += write (1, "0x", 2);
		printlen += ft_putnbr_base(frmt, va_arg(flag, size_t), 16);
	}
	else if (frmt == 'x' || frmt == 'X')
		printlen += ft_putnbr_base(frmt, va_arg(flag, size_t), 16);
	else if (frmt == 'd' || frmt == 'i')
		printlen += ft_putnbr_base(frmt, va_arg(flag, size_t), 10);
	return (printlen);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	printlen;
	va_list	flag;

	i = 0;
	printlen = 0;
	va_start(flag, format);
	while (format[i])
	{
		if (format[i] == '%')
			printlen += check_flags(flag, format[++i]);
		else
			printlen += ft_putchar(format[i]);
		i++;
	}
	va_end(flag);
	return (printlen);
}

#include <stdio.h>

int	main(void)
{
	int	a = 10;
	
	ft_printf("%c \n   %s   %%", 'h', "bon matin");
	printf("\n%c\n", 'h');
	ft_printf("%s", "bon matin");
	printf("\n%s\n", "bon matin");
	ft_printf("%d\n", 143536534);
	printf("%d\n", 143536534);
	ft_printf("%p\n", &a);
	printf("%p\n", &a);
	ft_printf("%x\n", 23432);
	printf("%x\n", 23432);
	ft_printf("%X\n", 23432);
	printf("%X\n", 23432);
	ft_printf("%X\n", 23432);
	printf("%i\n", a);
	ft_printf("%i\n", a);
	printf("%d\n", -23432);
	ft_printf("%d\n", -23432);
}
