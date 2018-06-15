/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argtype2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 19:26:17 by radler            #+#    #+#             */
/*   Updated: 2018/06/15 19:59:39 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*argtype_char(char *argtype, va_list ap)
{
	char arg;

	arg = va_arg(ap, char);
	if (ft_strstr(argtype, "hhi") || ft_strstr(argtype, "hhd"))
	{
		if (arg >= 0)
			return (ft_itoa_base((unsigned long long)arg, 10));
		else
			return (ft_negitoa((long long)arg));
	}
	return (NULL);
}

char	*argtype_long(char *argtype, va_list ap)
{
	long arg;
	int last;

	last = ft_strlen(argtype) - 1;
	arg = va_arg(ap, long);
	if (ft_strstr(argtype, "ld") || ft_strstr(argtype, "li" ||
			   	argtype[last] = 'D'))
	{
		if (arg >= 0)
			return (ft_itoa_base((unsigned long long)arg, 10));
		else
			return (ft_negitoa((long long)arg));
	}
	return (NULL);
}

char	*argtype_longlong(char *argtype, va_list ap)
{
	long long arg;

	arg = va_arg(ap, long long);
	if (ft_strstr(argtype, "lli") || ft_strstr(argtype, "lld"))
	{
		if (arg >= 0)
			return (ft_itoa_base((unsigned long long)arg, 10));
		else
			return (ft_negitoa(arg);
	}
	return (NULL);
}

char	*argtype_ushort(char *argtype, va_list ap)
{
	unsigned short arg;

	arg = va_arg(ap, unsigned short);
	arg = (unsigned long long)arg;
	if (ft_strstr(argtype, "ho"))
		return (ft_itoa_base(arg, 8));
	else if (ft_strstr(argtype, "hu"))
		return (ft_itoa_base(arg, 10));
	else if (ft_strstr(argtype, "hx"))
		return (ft_itoa_base(arg, 16));
	else if (ft_strstr(argtype, "hX"))
		return (ft_itoa_base(arg, 17));
	return (NULL);
}

char	*argtype_uchar(char *argtype, va_list ap)
{
	unsigned char arg;

	arg = va_arg(ap, unsigned char);
	if (argtype[ft_strlen(argtype) - 1] == 'c')
		return ((char *)&arg);
	else if (ft_strstr(argtype, "hhu"))
		return (ft_itoa_base((unsigned long long)arg, 10));
	else if (ft_strstr(argtype, "hhu"))
		return (ft_itoa_base((unsigned long long)arg, 10));
	else if (ft_strstr(argtype, "hhu"))
		return (ft_itoa_base((unsigned long long)arg, 10));
	else if (ft_strstr(argtype, "hhu"))
		return (ft_itoa_base((unsigned long long)arg, 10));
	return (NULL);
}
