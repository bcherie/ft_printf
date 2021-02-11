/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:43:05 by bcherie           #+#    #+#             */
/*   Updated: 2021/01/27 18:43:53 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse_type(char *ptr, va_list list, t_my_struct *new)
{
	if (*ptr == 'c' || *ptr == '%')
	{
		new->type = *ptr;
		ptr = ft_p_c(ptr, new, list);
	}
	if (*ptr == 's')
	{
		new->type = 's';
		ft_p_s(ptr, new, list);
	}
	if (*ptr == 'd' || *ptr == 'i' || *ptr == 'u')
	{
		new->type = *ptr;
		ptr = ft_p_d_i_u(ptr, new, list);
	}
	ft_parse_type_two(ptr, list, new);
	return (ptr);
}

char	*ft_parse_type_two(char *ptr, va_list list, t_my_struct *new)
{
	if (*ptr == 'p')
	{
		new->type = 'p';
		ptr = ft_p_p(ptr, list, new);
	}
	if (*ptr == 'x' || *ptr == 'X')
	{
		new->type = *ptr;
		ptr = ft_p_x(ptr, new, list);
	}
	return (ptr);
}
