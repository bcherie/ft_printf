
#include "ft_printf.h"

void	work_fl_u_x(char *str, t_my_struct *new)
{
	int len;

	len = ft_strlen(str);
	if (new->precision == 0 && *str == '0')
		print_space(new);
	else if (new->min == '-' || new->min == '-')
		print_left(str, len, new);
	else if (new->nul == '0' && (new->precision < 0))
		print_nul(str, len, new);
	else
		print_right(str, len, new);
}
