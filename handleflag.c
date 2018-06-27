#include "ft_printf.h"

char	*handleflag(char *argform, char *str)
{
	int	prec;
	int 	min;
	char	*tmp;

	min = 0;
	prec = getprec(argform);
	min = getminsize(argform);
	if (argform[ft_strlen(argform) - 1] == 'p')
		min -= 2;
	if (ft_strstr(argform, ".") && prec > -1)
		str = handleprec(prec, argform, str);
	if (is_zero(argform) && !ft_strstr(argform, "-"))
		str = handlezero(min, argform, str);
	if (ft_strstr(argform, "#"))
		str = handlehashtag(prec, argform, str);
	if (ft_strstr(argform, "p"))
		ft_strbackconc(&str, "0x");
	if (ft_strstr(argform, "+") || ft_strstr(argform, " "))
		str = handlespaceplus(prec, argform, str);
	if (min > 0)
		str = handleminsize(min, argform, str);
	return (str);
}