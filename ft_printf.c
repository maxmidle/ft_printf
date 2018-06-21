/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:47:35 by radler            #+#    #+#             */
/*   Updated: 2018/06/21 21:30:02 by radler           ###   ########.fr       */
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
	char *buff;

	i = 0;
	va_start(ap, format);
	str = ft_strnew(0);
	while (format[i])
	{
		if (format[i] != '%')
			ft_strnconc(&str, ft_strlen(str), (char *)&format[i], 1);
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_strconc(&str, "%");
			i++;
		}
		else if (format[i] == '%')
		{
			argform = getargform(&format[i]);
			if(!(buff = sendarg(argform, ap)))
				return (-1);
			ft_strconc(&str, buff);
			ft_strdel(&buff);
			i = i + ft_strlen(argform);
		}
		i++;
	}
	free (argform);
	ft_putstr(str);
	return (ft_strlen(str));
}

char	*sendarg(char *argform, va_list ap)
{
	char *(*f)(char *argtype, va_list ap);
	char *argtype;
	char **argtab;
	int i;

	i = 0;
	argtype = getargtype(argform);
	argtab = argtabinit();
	while (!ft_strstr(argtab[i], argtype))
		i++;
	if (i >= 17)
		return (NULL);
	f = ptrfuninit(i);
	return (f(argtype, ap));
}
#include <locale.h>
int main()
{
	char *l = setlocale(LC_ALL, "");
	long long a = 9223372036854775807;
	unsigned long long b = 18446744073709551614;
	wchar_t c[] = L"test de chainée";
	char *e = "test de chaine";
	wint_t d = 233;
	printf("%d\n", (ft_printf("%lld et %llu puis %ls encore %lc et enfin %s\n", a, b, c, d, e)));
	ft_putnbr(printf("%lld et %llu puis %ls encore %lc et enfin %s\n", a, b, c, d, e));
	return (0);
}
