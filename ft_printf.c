/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:47:35 by radler            #+#    #+#             */
/*   Updated: 2018/06/13 19:01:50 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
int		ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	char *str;
	char *argform;
	char *argtype;
	char **argtab;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i]);
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar('%');
			i++;
		}
		else if (format[i] == '%')
		{
			argform = getargform(&format[i]);
			argtype = getargtype(argform);
			ft_putchar('|');
			ft_putstr(argform);
			ft_putchar('-');
			ft_putstr(argtype);
			ft_putchar('|');
			str = argtype_charchar(argtype, ap);
			ft_putstr(str);
			while (!ft_isarg(format[i]))
				i++;
		}
		i++;
	}
	free (argform);
	free (argtype);
	return (0);
}
int main()
{
	long long a = 9223372036854775802;
	char b = 92;
	ft_printf("pour obtenir de l'%s \nil faut faire des %% de 16.\n", "hexadecimal");
	printf("________________________________________\n, il faut %c quilles, et %s\n", b, "Alain");
	return (0);
}
