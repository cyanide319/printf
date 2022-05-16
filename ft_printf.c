/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoin <tbeaudoin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:11:18 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/05/16 15:03:34 by tbeaudoin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int check_flags(va_list flag, const char frmt)
{
    size_t printlen;

    if (frmt == 'c')
        printlen += write(1, va_arg(flag, int), 1);
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
    }
    va_end(flag);
    return (printlen);
}

int main()
{
    ft_printf("%c", "h");
}