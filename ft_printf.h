/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:11:23 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/05/20 16:35:30 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

# define B_10 "0123456789"
# define B_16L "0123456789abcdef"
# define B_16U "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		check_flags(va_list flag, const char frmt);
void	ft_putnbr(int nb, size_t *count);
int		ft_putchar(char c);
void	ft_putstr(char *str, size_t *count);
void	ft_putnbr_base(char flag, size_t nb, size_t base, size_t *count);

#endif