/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:41:41 by bcherie           #+#    #+#             */
/*   Updated: 2021/01/27 18:42:32 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_fl(char *ptr, t_my_struct *new)
{
	while (*ptr == '-' || *ptr == '0')
	{
		if (*ptr == '-')
			new->min = '-';
		if (*ptr == '0')
			new->nul = '0';
		ptr++;
	}
	if (new->min == '-')
		new->nul = 0;
	return (ptr);
}

char	*ft_parse_width(char *ptr, va_list list, t_my_struct *new)
{
	while (*ptr >= '0' && *ptr <= '9')
	{
		new->width = new->width * 10 + (*ptr - '0');
		if (*(ptr + 1) == '\0')
			return (ptr);
		ptr++;
	}
	if (*ptr == '*')
	{
		new->width = va_arg(list, int);
		ptr++;
		if (new->width < 0)
		{
			new->width *= -1;
			new->min = '-';
		}
	}
	return (ptr);
}

char	*ft_parse_perc(char *ptr, va_list list, t_my_struct *new)
{
	if (*ptr != '*' || !(*ptr >= '0' && *ptr <= '9'))
		new->precision = 0;
	while (*ptr >= '0' && *ptr <= '9')
	{
		if (!(*ptr >= '0' && *ptr <= '9'))
			new->precision = 0;
		new->precision = new->precision * 10 + (*ptr - '0');
		ptr++;
	}
	if (*ptr == '*')
	{
		new->precision = va_arg(list, int);
		ptr++;
		if (new->precision < 0)
			new->precision = -1;
	}
	return (ptr);
}
