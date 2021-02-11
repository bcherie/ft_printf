/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_fl_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:08:09 by bcherie           #+#    #+#             */
/*   Updated: 2021/01/27 20:09:45 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_null_ptr(char *str, int len, t_my_struct *new)
{
	new->g_length += write(1, "0x", 2);
	while (new->width-- > len)
		new->g_length += write(1, "0", 1);
	while (*str)
		new->g_length += write(1, str++, 1);
}

static void		print_space_ptr(t_my_struct *new)
{
	if (new->width > 2)
		while (new->width-- > 2)
			new->g_length += write(1, " ", 1);
	new->g_length += write(1, "0x", 2);
}

static void		print_left_ptr(char *str, int len, t_my_struct *new)
{
	int		newlen;

	newlen = len;
	if (new->precision > len)
		newlen = new->precision;
	else if (new->precision < len)
		newlen = len + 2;
	new->g_length += write(1, "0x", 2);
	while (new->precision-- > len)
		new->g_length += write(1, "0", 1);
	while (*str)
		new->g_length += write(1, str++, 1);
	while (new->width-- > newlen)
		new->g_length += write(1, " ", 1);
}

static void		print_right_ptr(char *str, int len, t_my_struct *new)
{
	int		newlen;

	newlen = len;
	if (new->precision > len)
		newlen = new->precision;
	else if (new->precision < len)
		newlen = len + 2;
	while (new->width-- > newlen)
		new->g_length += write(1, " ", 1);
	new->g_length += write(1, "0x", 2);
	while (new->precision-- > len)
		new->g_length += write(1, "0", 1);
	while (*str)
		new->g_length += write(1, str++, 1);
}

void			ft_work_flags_p(char *str, t_my_struct *new)
{
	int		len;

	len = ft_strlen(str);
	if (new->precision == 0 && *str == '0')
		print_space_ptr(new);
	else if (new->min == '-')
		print_left_ptr(str, len, new);
	else if (new->nul == '0' && new->precision == -1)
		print_null_ptr(str, len, new);
	else
		print_right_ptr(str, len, new);
}
