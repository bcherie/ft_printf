
#include "ft_printf.h"

void	ft_init(t_my_struct *new)
{
	new->type = 0;
	new->width = 0;
	new->min = 0;
	new->nul = 0;
	new->precision = -1;
	new->string_free = 0;
}
