/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:46:17 by bcherie           #+#    #+#             */
/*   Updated: 2021/01/27 18:46:39 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_p_x(char *ptr, t_my_struct *new, va_list list)
{
	char			*str;
	unsigned long	x;

	x = va_arg(list, unsigned int);
	str = itoa_b(x, new);
	work_fl_u_x(str, new);
	free(str);
	return (ptr);
}
