#include "ft_printf.h"

char	*handlespaceplus(int prec, char *argform, char *str)
{
	char last;
	char *sign;

	last = argform[ft_strlen(argform) - 1];
	if (ft_strstr(argform, "+"))
		sign = ft_strdup("+");
	else
		sign = ft_strdup(" ");
	if (last == 'd' || last == 'D' || last == 'i')
	{
		if (str[0] != '-')
		{
			if (str[0] == '0' && prec == -1)
				str[0] = sign[0];
			else
				ft_strbackconc(&str, sign);
		}
	}
	ft_strdel(&sign);
	return (str);
}
