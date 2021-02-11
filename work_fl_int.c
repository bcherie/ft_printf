/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_fl_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:05:45 by bcherie           #+#    #+#             */
/*   Updated: 2021/01/27 20:07:43 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nul(char *str, int len, t_my_struct *new)
{
	if (str[0] == '-')
	{
		new->g_length += write(1, "-", 1);
		str = str + 1;
	}
	while (new->width-- > len)
		new->g_length += write(1, "0", 1);
	while (*str)
		new->g_length += write(1, str++, 1);
}

void	print_space(t_my_struct *new)
{
	if (new->width > 0)
		while (new->width--)
			new->g_length += write(1, " ", 1);
}

void	print_left(char *str, int len, t_my_struct *new)
{
	int		newlen;

	newlen = len;
	if (new->precision > len)
		newlen = new->precision;
	if (str[0] == '-')
	{
		new->g_length += write(1, "-", 1);
		str = str + 1;
		len -= 1;
		if ((new->width > newlen && new->precision != -1)
			&& ((new->precision > new->width) || (new->precision > len)))
			newlen += 1;
	}
	while (new->precision-- > len)
		new->g_length += write(1, "0", 1);
	while (*str)
		new->g_length += write(1, str++, 1);
	while (new->width-- > newlen)
		new->g_length += write(1, " ", 1);
}

void	print_right(char *str, int len, t_my_struct *new)
{
	int		newlen;

	newlen = len;
	if (new->precision > len)
		newlen = new->precision;
	if (str[0] == '-')
	{
		len -= 1;
		if ((new->width > newlen && new->precision != -1)
			&& ((new->precision > new->width) || (new->precision > len)))
			newlen += 1;
	}
	while (new->width-- > newlen)
		new->g_length += write(1, " ", 1);
	if (str[0] == '-')
	{
		new->g_length += write(1, "-", 1);
		str = str + 1;
	}
	while (new->precision-- > len)
		new->g_length += write(1, "0", 1);
	while (*str)
		new->g_length += write(1, str++, 1);
}

void	ft_work_flags_di(char *str, t_my_struct *new)
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
