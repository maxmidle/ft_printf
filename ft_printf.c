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

int		ft_printf(const char *format, ...)
{
	int		i;
	int	size;
	va_list	ap;
	char *str;

	i = 0;
	va_start(ap, format);
	str = ft_strnew(0);
	size = 0;
	while (format[i])
	{
		str = ft_strcdup(&format[i], '%');
		i += ft_strlen(str);
		if (format[i] == '%')
		{
			if ((i += getargflag(&format[i], &str, ap)) < 0)
				return (-1);
		}
		size += ft_strlen(str);
		ft_putstr(str);
		ft_strdel(&str);
	}
	return (size);
}

char	*getarg(char *argform, va_list ap)
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
	ft_freetab(argtab);
	free(argtype);
	return (f(argtype, ap));
}

int	getargflag(const char *format, char **str, va_list ap)
{
	char	*argform;
	char	*buff;
	int	i;

	if (format[1] == '%')
	{
		ft_strconc(str, "%");
		return (2);
	}
	argform = getargform(format);
	if(!(buff = getarg(argform, ap)))
		return (-2147468648);
	buff = handleflag(argform, buff);
	ft_strconc(str, buff);
	i = ft_strlen(argform);
	ft_strdel(&buff);
	ft_strdel(&argform);
	return (i + 1);
}
#include <locale.h>
int main()
{
	char *l = setlocale(LC_ALL, "");
	long long f = -9223372036854775808;
	long long a = 6541;
	unsigned long long b = 18446744073709551614;
	wchar_t *c = L"tèst";
	char *e = "test";
	wint_t d = 256;
	char g = 'g';
	int ret;
	ret = ft_printf("%+-20.15lld et %#llX puisé%% dot %010.ls encore %lc et enfin %010p\n", a, b, c, d, e);
	printf("%d\n", ret);
	ret = printf("%+-20.15lld et %#llX puisé%% dot %010.ls encore %lc et enfin %010p\n", a, b, c, d, e);
ret = sizeof(*c);
printf("%d\n", ret);
	return (0);
}
