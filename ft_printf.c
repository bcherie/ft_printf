
#include "ft_printf.h"

char	*ft_parser(char *ptr, va_list list, t_my_struct *new)
{
	ft_init(new);
	if (*ptr == '\0')
		return ("0");
	if (*ptr == '-' || *ptr == '0')
		ptr = ft_parse_fl(ptr, new);
	if ((*ptr >= '0' && *ptr <= '9') || (*ptr == '*'))
		ptr = ft_parse_width(ptr, list, new);
	if (*ptr == '.')
	{
		ptr++;
		ptr = ft_parse_perc(ptr, list, new);
	}
	else
		new->precision = -1;
	if ((ft_strchr("cspdiuxX%", *ptr)))
		ptr = ft_parse_type(ptr, list, new);
	else
		return ("0");
	return (ptr);
}

int		ft_printf(const char *s, ...)
{
	va_list		list;
	t_my_struct	new;
	char		*ptr;

	ptr = (char *)s;
	va_start(list, s);
	new.g_length = 0;
	while (*ptr)
	{
		if (*ptr != '%')
			new.g_length += write(1, ptr, 1);
		else if (*ptr == '%')
		{
			ptr++;
			ptr = ft_parser(ptr, list, &new);
		}
		ptr++;
	}
	va_end(list);
	return (new.g_length);
}
