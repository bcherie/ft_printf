
#include "ft_printf.h"

static int	base_digit(unsigned long num)
{
	unsigned long i;

	i = 0;
	while (num)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

char		*itoa_b(unsigned long num, t_my_struct *new)
{
	char			*ptr;
	const char		*sym;
	unsigned long	len;

	if (new->type == 'X')
		sym = "0123456789ABCDEF";
	if (new->type == 'x' || new->type == 'p')
		sym = "0123456789abcdef";
	len = base_digit(num);
	if (!(ptr = (char *)malloc(sizeof(char *) * len + 1)))
		return (0);
	ptr[len] = '\0';
	if (num == 0)
	{
		ptr[0] = '0';
		return (ptr);
	}
	while (num != 0)
	{
		len--;
		ptr[len] = sym[num % 16];
		num /= 16;
	}
	return (ptr);
}
