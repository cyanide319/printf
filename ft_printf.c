/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:09:25 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/05/20 16:39:23 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
			printlen += write(1, &format[i], 1);
		i++;
	}
	va_end(flag);
	return (printlen);
}

// int	main(void)
// {
// 	int	a = -10;
// 	int ret;
	
// 	ret = ft_printf("%s\n", "bon matin");
// 	ft_printf("%d\n", ret);
// 	ret = printf("%s\n", "bon matin");
// 	printf("%d\n", ret);
// 	// printf("\n%c\n", 'h');
// 	// ft_printf("%s", "bon matin");
// 	// printf("\n%s\n", "bon matin");
// 	// ft_printf("%d\n", 143536534);
// 	// printf("%d\n", 143536534);
// 	ft_printf("%p\n", &a);
// 	printf("%p\n", &a);
// 	ret = ft_printf("%x\n", 23432);
// 	ft_printf("%d\n", ret);
// 	ret = printf("%x\n", 23432);
// 	printf("%d\n", ret);
// 	// ft_printf("%X\n", 23432);
// 	// printf("%X\n", 23432);
// 	// ft_printf("%X\n", 23432);
// 	// printf("%i\n", a);
// 	// ft_printf("%i\n", a);
// 	// printf("%i\n", -23432);
// 	// ft_printf("%i\n", -23432);
// 	// printf("%d\n", a);
// 	// ft_printf("%d\n", a);
// 	ret = printf("%d\n", -23432);
// 	printf("%d\n", ret);
// 	ret = ft_printf("%d\n", -23432);
// 	ft_printf("%d\n", ret);
	
// }
