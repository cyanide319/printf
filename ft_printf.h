/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoin <tbeaudoin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:11:23 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/05/16 15:01:59 by tbeaudoin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

# define B_10 "0123456789"
# define B_16L "0123456789abcdef"
# define B_16U "0123456789ABCDEF"

int	ft_printf(const char *format, ...);

#endif