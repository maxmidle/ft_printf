/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:49:01 by radler            #+#    #+#             */
/*   Updated: 2018/06/13 18:54:32 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);

char	**argtabinit();
char	*getargtype(char *argform);
char	*getargform(const char *format);
int		ft_isarg(char c);

char	*ft_itoa_base(unsigned long long value, unsigned long long base);
char	*ft_negitoa(long long value);

char	*argtype_int(char *argtype, va_list ap);
char	*argtype_uint(char *argtype, va_list ap);
char	*argtype_charchar(char *argtype, va_list ap);
char	*argtype_void(char *argtype, va_list ap);
char	*argtype_short(char *argtype, va_list ap);
#endif
