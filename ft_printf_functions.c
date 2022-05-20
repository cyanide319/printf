/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:11:18 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/05/20 16:41:03 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, size_t *count)
{
	while (*str)
		*count += write(1, str++, 1);
}

void	ft_putnbr_base(char flag, size_t nb, size_t base, size_t *count)
{
	if (nb >= base)
		ft_putnbr_base(flag, (nb / base), base, count);
	if (flag == 'x' || flag == 'p')
		*count += write (1, &B_16L[nb % base], 1);
	else if (flag == 'X')
		*count += write (1, &B_16U[nb % base], 1);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

void	ft_putnbr(int nb, size_t *count)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10, count);
		*count += ft_putchar('8');
	}
	else if (nb < 0)
	{
		*count += ft_putchar('-');
		ft_putnbr(-nb, count);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
		ft_putnbr(nb % 10, count);
	}
	else
		*count += ft_putchar(nb + 48);
}

int	check_flags(va_list flag, const char frmt)
{
	size_t	printlen;

	printlen = 0;
	if (frmt == 'c')
		printlen += ft_putchar(va_arg(flag, int));
	else if (frmt == 's')
		ft_putstr(va_arg(flag, char *), &printlen);
	else if (frmt == '%')
		printlen += write(1, "%", 1);
	else if (frmt == 'u')
		ft_putnbr_base(frmt, va_arg(flag, size_t), 10, &printlen);
	else if (frmt == 'p')
	{
		printlen += write (1, "0x", 2);
		ft_putnbr_base(frmt, va_arg(flag, size_t), 16, &printlen);
	}
	else if (frmt == 'x' || frmt == 'X')
		ft_putnbr_base(frmt, va_arg(flag, size_t), 16, &printlen);
	else if (frmt == 'd' || frmt == 'i')
		ft_putnbr(va_arg(flag, int), &printlen);
	return (printlen);
}