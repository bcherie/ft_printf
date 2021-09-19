
#include "ft_printf.h"

void	print_n(t_my_struct *new, int len_n)
{
	while (len_n > 0)
	{
		new->g_length += write(1, "0", 1);
		len_n--;
	}
}
