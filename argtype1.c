/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argtype1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:09:47 by radler            #+#    #+#             */
/*   Updated: 2018/06/13 19:03:37 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*argtype_int(char *argtype, va_list ap)
{
	int last;
	int arg;

	last = ft_strlen(argtype) - 1;
	arg = va_arg(ap, int);
	if (argtype[last] == 'd' || argtype[last] == 'i')
	{
		if (arg >= 0)
			return (ft_itoa_base((unsigned long long)arg, 10));
		else
			return (ft_negitoa((long long)arg));
	}
	return (NULL);
}

char	*argtype_uint(char *argtype, va_list ap)
{
	int				last;
	unsigned int	arg;

	last = ft_strlen(argtype) - 1;
	arg = va_arg(ap, unsigned int);
	arg = (unsigned long long)arg;
	if (argtype[last] == 'o')
		return (ft_itoa_base(arg, 8));
	else if (argtype[last] == 'u')
		return (ft_itoa_base(arg, 10));
	else if (argtype[last] == 'x')
		return (ft_itoa_base(arg, 16));
	else if (argtype[last] == 'X')
		return (ft_itoa_base(arg, 17));
	return (NULL);
}

char	*argtype_charchar(char *argtype, va_list ap)
{
	int		last;
	char	*arg;

	last = ft_strlen(argtype) - 1;
	arg = va_arg(ap, char *);
	if (argtype[last] == 's')
		return (arg);
	return (NULL);
}

char	*argtype_void(char *argtype, va_list ap)
{
	int		last;
	void	*arg;
	char	*str;
	char	*tmp;

	last = ft_strlen(argtype) - 1;
	arg = va_arg(ap, void *);
	if (argtype[last] == 'p')
	{
		str = ft_strdup("0x");
		tmp = ft_itoa_base((unsigned long long)arg, 16);
		ft_strconc(&str, tmp);
		free(tmp);
		return (str);
	}
	return (NULL);
}

char	*argtype_short(char *argtype, va_list ap)
{
	int		last;
	short	arg;

	last = ft_strlen(argtype) - 1;
	arg = va_arg(ap, short);
	if (ft_strstr(argtype, "hi") || ft_strstr(argtype, "hd"))
	{
		if (arg >= 0)
			return (ft_itoa_base((unsigned long long)arg, 10));
		else
			return (ft_negitoa((long long)arg));
	}
	return (NULL);
}
