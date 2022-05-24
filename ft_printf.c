/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:09:25 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/05/23 13:23:06 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			check_flags(&flag, format[++i], &printlen);
		else
			printlen += write(1, &format[i], 1);
		i++;
	}
	va_end(flag);
	return (printlen);
}
