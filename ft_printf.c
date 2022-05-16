/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoin <tbeaudoin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:11:18 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/05/16 16:18:04 by tbeaudoin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int check_flags(va_list flag, const char frmt)
{
    size_t printlen;

    printlen = 0;
    if (frmt == 'c')
        printlen += ft_putchar(va_arg(flag, int));
    return (printlen);
}

int	ft_printf(const char *format, ...)
{
    size_t  i;
    size_t  printlen;
    va_list flag;

    i = 0;
    printlen = 0;
    va_start(flag, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            printlen += check_flags(flag, format[i + 1]);
            i++;
        }
        else
            printlen += ft_putchar(format[i]);
        i++;
    }
    va_end(flag);
    return (printlen);
}

int main()
{
    ft_printf("%c", 'h');
}