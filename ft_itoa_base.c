/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radler <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:06:20 by radler            #+#    #+#             */
/*   Updated: 2018/06/13 19:07:53 by radler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned long long value, unsigned long long base)
{
	char	*hexstr;
	char	*ret;
	int		buff;

	if (base < 2 || base > 17)
		return (NULL);
	ret = ft_strnew(0);
	hexstr = ft_strdup("0123456789abcdef");
	if (base == 17)
	{
		hexstr = ft_upcase(hexstr);
		base--;
	}
	while (value >= base)
	{
		buff = (value % base);
		ret = ft_strnconc(&ret, ft_strlen(ret), &hexstr[buff], 1);
		value /= base;
	}
	buff = value;
	ft_strnconc(&ret, ft_strlen(ret), &hexstr[buff], 1);
	ret = ft_strrev(ret);
	free(hexstr);
	return (ret);
}

char	*ft_negitoa(long long value)
{
	int					size;
	char				*str;
	unsigned long long	tmp;

	size = 2;
	str = NULL;
	tmp = value * -1;
	if (tmp == 9223372036854775808)
		return (ft_strdup("-9223372036854775808"));
	while (tmp >= 10)
	{
		size++;
		tmp /= 10;
	}
	str = ft_strnew(size);
	if (value <= 0 || str == NULL)
		return (NULL);
	while (size--)
	{
		str[size] = value % 10 + 48;
		value /= 10;
	}
	str[size] = value + 48;
	str[0] = '-';
	return (str);
}
#include <stdio.h>
int main()
{
	char *str;
	unsigned long long b = 18446744073709551614;
	long long c = -9223372036854775808;
	int a = 2256854;
	void *ptr;
	ptr = &a;
	printf("%llu\n", b);
	str = ft_negitoa(c);
	printf("%s\n", str);
	printf("%p\n", ptr);
	printf("%d\n", a);
	str = ft_negitoa(a);
	printf("%s\n", str);
	free(str);
	return (0);
}
