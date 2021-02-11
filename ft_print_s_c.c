/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:45:37 by bcherie           #+#    #+#             */
/*   Updated: 2021/01/27 18:45:50 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_p_s(char *ptr, t_my_struct *new, va_list list)
{
	char	*str;

	if (new->type == 's')
	{
		str = va_arg(list, char *);
		work_flags(str, new);
	}
	return (ptr);
}

static void	if_nul_from_c(char c, int len_n, t_my_struct *new)
{
	len_n = new->width - 1;
	print_n(new, len_n);
	new->g_length += write(1, &c, 1);
}

static void	if_no_nul_from_c(char c, t_my_struct *new)
{
	new->g_length += write(1, &c, 1);
	while (new->width - 1 > 0)
	{
		new->g_length += write(1, " ", 1);
		new->width--;
	}
}

char		*ft_p_c(char *ptr, t_my_struct *new, va_list list)
{
	char	c;
	int		len_n;

	len_n = 0;
	if (new->type == '%')
		c = '%';
	else
		c = va_arg(list, int);
	if (new->nul == '0' && new->min != '-' && new->width > 1)
		if_nul_from_c(c, len_n, new);
	if (!(new->nul == '0') && new->min == '-')
		if_no_nul_from_c(c, new);
	if (!(new->nul == '0') && new->min != '-')
	{
		while (new->width - 1 > 0)
		{
			new->g_length += write(1, " ", 1);
			new->width--;
		}
		new->g_length += write(1, &c, 1);
	}
	return (ptr);
}
