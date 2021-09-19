
#include "ft_printf.h"

char	*ft_p_d_i_u(char *ptr, t_my_struct *new, va_list list)
{
	int				di;
	char			*str;
	unsigned int	u;

	if (new->type == 'd' || new->type == 'i')
	{
		di = va_arg(list, int);
		str = ft_itoa(di);
		ft_work_flags_di(str, new);
		free(str);
	}
	if (new->type == 'u')
	{
		u = va_arg(list, unsigned int);
		str = ft_itoa_uns(u);
		ft_work_flags_di(str, new);
		free(str);
	}
	return (ptr);
}

char	*ft_p_p(char *ptr, va_list list, t_my_struct *new)
{
	unsigned long	p;
	char			*s;

	p = va_arg(list, unsigned long);
	s = itoa_b(p, new);
	ft_work_flags_p(s, new);
	free(s);
	return (ptr);
}
