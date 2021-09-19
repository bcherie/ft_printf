
#include "ft_printf.h"

void	if_nul_fl(char *str, t_my_struct *new, int len)
{
	if (new->nul == '0')
	{
		while (new->width-- - len > 0)
			new->g_length += write(1, "0", 1);
		while (*str)
			new->g_length += write(1, str++, 1);
	}
	else
	{
		while (new->width-- - len > 0)
			new->g_length += write(1, " ", 1);
		while (*str)
			new->g_length += write(1, str++, 1);
	}
}

void	work_flags(char *str, t_my_struct *new)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (new->precision != -1 && new->precision < len)
	{
		str = ft_substr(str, 0, new->precision);
		new->string_free = str;
	}
	len = ft_strlen(str);
	if (new->min != '-')
		if_nul_fl(str, new, len);
	else
	{
		while (*str)
			new->g_length += write(1, str++, 1);
		while (new->width-- - len > 0)
			new->g_length += write(1, " ", 1);
	}
	if (new->string_free)
		free(new->string_free);
}
