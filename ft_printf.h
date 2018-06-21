/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:49:01 by radler            #+#    #+#             */
/*   Updated: 2018/06/21 21:25:45 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "libft/libft.h"
# include <stdlib.h>

int		ft_printf(const char *format, ...);
char    *sendarg(char *argform, va_list ap);

char	**argtabinit();
char	*getargtype(char *argform);
char	*getargform(const char *format);
int		ft_isarg(char c);
char	*(*ptrfuninit(int i))(char *, va_list);

char	*ft_itoa_base(unsigned long long value, unsigned long long base);
char	*ft_negitoa(long long value);

char	*argtype_int(char *argtype, va_list ap);
char	*argtype_uint(char *argtype, va_list ap);
char	*argtype_charchar(char *argtype, va_list ap);
char	*argtype_void(char *argtype, va_list ap);
char	*argtype_short(char *argtype, va_list ap);
char	*argtype_char(char *argtype, va_list ap);
char	*argtype_long(char *argtype, va_list ap);
char	*argtype_longlong(char *argtype, va_list ap);
char	*argtype_ushort(char *argtype, va_list ap);
char	*argtype_uchar(char *argtype, va_list ap);
char	*argtype_ulong(char *argtype, va_list ap);
char	*argtype_ulonglong(char *argtype, va_list ap);
char	*argtype_intmax_t(char *argtype, va_list ap);
char	*argtype_uintmax_t(char *argtype, va_list ap);
char	*argtype_size_t(char *argtype, va_list ap);
char	*argtype_wint_t(char *argtype, va_list ap);
char	*argtype_wchar_t(char *argtype, va_list ap);
char	*ft_witoa(wint_t nbr);
#endif
