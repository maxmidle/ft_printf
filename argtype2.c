/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argtype2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:26:17 by radler            #+#    #+#             */
/*   Updated: 2018/06/21 18:47:34 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*argtype_char(char *argtype, va_list ap)
{
	char argu;

	argu = (char)va_arg(ap, int);
	if (ft_strstr(argtype, "hhi") || ft_strstr(argtype, "hhd"))
	{
		if (argu >= 0)
			return (ft_itoa_base((unsigned long long)argu, 10));
		else
			return (ft_negitoa((long long)argu));
	}
	return (NULL);
}

char	*argtype_long(char *argtype, va_list ap)
{
	long argu;
	int last;

	last = ft_strlen(argtype) - 1;
	argu = va_arg(ap, long);
	if (ft_strstr(argtype, "ld") || ft_strstr(argtype, "li") ||
			   	argtype[last] == 'D')
	{
		if (argu >= 0)
			return (ft_itoa_base((unsigned long long)argu, 10));
		else
			return (ft_negitoa((long long)argu));
	}
	return (NULL);
}

char	*argtype_longlong(char *argtype, va_list ap)
{
	long long argu;

	argu = va_arg(ap, long long);
	if (ft_strstr(argtype, "lli") || ft_strstr(argtype, "lld") ||
			ft_strstr(argtype, "zi") || ft_strstr(argtype, "zd"))
	{
		if (argu >= 0)
			return (ft_itoa_base((unsigned long long)argu, 10));
		else
			return (ft_negitoa(argu));
	}
	return (NULL);
}

char	*argtype_ushort(char *argtype, va_list ap)
{
	unsigned short argu;

	argu = (unsigned short)va_arg(ap, unsigned int);
	argu = (unsigned long long)argu;
	if (ft_strstr(argtype, "ho"))
		return (ft_itoa_base(argu, 8));
	else if (ft_strstr(argtype, "hu"))
		return (ft_itoa_base(argu, 10));
	else if (ft_strstr(argtype, "hx"))
		return (ft_itoa_base(argu, 16));
	else if (ft_strstr(argtype, "hX"))
		return (ft_itoa_base(argu, 17));
	return (NULL);
}

char	*argtype_uchar(char *argtype, va_list ap)
{
	unsigned char	argu;
	char			*c;

	c = (char *)&argu;
	argu = (unsigned char)va_arg(ap, unsigned int);
	if (argtype[ft_strlen(argtype) - 1] == 'c')
		return (ft_strndup(c, 1));
	else if (ft_strstr(argtype, "hhu"))
		return (ft_itoa_base((unsigned long long)argu, 10));
	else if (ft_strstr(argtype, "hhu"))
		return (ft_itoa_base((unsigned long long)argu, 10));
	else if (ft_strstr(argtype, "hhu"))
		return (ft_itoa_base((unsigned long long)argu, 10));
	else if (ft_strstr(argtype, "hhu"))
		return (ft_itoa_base((unsigned long long)argu, 10));
	return (NULL);
}
