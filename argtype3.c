#include "ft_printf.h"

char	*argtype_ulong(char *argtype, va_list ap)
{
	unsigned long	arg;
	int		last;

	last = ft_strlen(argtype) - 1;
	arg = va_arg(ap, unsigned long);
	arg = (unsigned long long)arg;
	if (argtype[last] == 'O' || ft_strstr(argtype, "lo"))
		return (ft_itoa_base(arg, 8));
	else if (argtype[last] == 'U' || ft_strstr(argtype, "lu"))
		return (ft_itoa_base(arg, 10));
	else if (ft_strstr(argtype, "lx"))
		return (ft_itoa_base(arg, 16));
	else if (ft_strstr(argtype, "lX"))
		return (ft_itoa_base(arg, 17));
	return (NULL);
}

char	*argtype_ulonglong(char *argtype, va_list ap)
{
	unsigned long long arg;

	arg = va_arg(ap, unsigned long long);
	 if (ft_strstr(argtype, "llo"))
		return (ft_itoa_base(arg, 8));
	else if (ft_strstr(argtype, "llu"))
		return (ft_itoa_base(arg, 10));
	else if (ft_strstr(argtype, "llx"))
		return (ft_itoa_base(arg, 10));
	else if (ft_strstr(argtype, "llX"))
		return (ft_itoa_base(arg, 17));
	return (NULL);
}

char	*argtype_intmax_t(char *argtype, va_list ap)
{
	intmax_t arg;

	arg = va_arg(ap, intmax_t);
	if (ft_strstr(argtype, "jd") || ft_strstr(argtype, "ji"))
	{
		if (arg >= 0)
			return(ft_itoa_bas((unsigned long long)arg, 10));
		return (ft_negitoa((long long)arg));
	}
	return (NULL);
}

char	*argtype_uintmax_t(char *argtype, va_list ap)
{
	uintmax_t arg;

	arg = va_arg(ap, uintmax_t);
	arg = (unsigned long long)arg;
	if (ft_strstr(argtype, "jo"))
		return (ft_itoa_base(arg, 8));
	else if (ft_strstr(argtype, "ju"))
		return (ft_itoa_base(arg, 10));
	else if (ft_strstr(argtype, "jx"))
		return (ft_itoa_base(arg, 16));
	else if (ft_strstr(argtype, "jX"))
		return (ft_itoa_base(arg, 17));
	return (NULL);
}

char	*argtype_size_t(char *argtype, va_list ap)
{
	size_t arg;

	arg = va_arg(ap, size_t);
	if (ft_strstr(argtype, "zd ") || ft_strstr(argtype, "zi"))
	{
		if (arg >= 0)
			return (ft_itoa_base((unsigned long long)arg, 10));
		return (ft_negito((long long)arg));
	}
	else if (ft_strstr(argtype, "zo"))
		return (ft_itoa_base((unsigned long long)arg, 8));
	else if (ft_strstr(argtype, "zu"))
		return (ft_itoa_base((unsigned long long)arg, 10));
	else if (ft_strstr(argtype, "zx"))
		return (ft_itoa_base((unsigned long long)arg, 16));
	else if (ft_strstr(argtype, "zX"))
		return (ft_itoa_base((unsigned long long)arg, 17));
	return (NULL);
}
