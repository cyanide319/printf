/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:11:23 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/05/13 16:18:54 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

# define B_10 "0123456789"
# define B_16 "0123456789abcdef"
# define B_16X "0123456789ABCDEF"

int	ft_printf(const char *fmt, ...);

#endif