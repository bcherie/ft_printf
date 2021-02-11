/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcherie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 18:56:08 by bcherie           #+#    #+#             */
/*   Updated: 2021/01/27 18:59:34 by bcherie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_my_struct
{
	char		type;
	int			width;
	int			min;
	int			nul;
	int			precision;
	int			g_length;
	char		*string_free;
}				t_my_struct;

int				ft_printf(const char *s, ...);
int				ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);
void			ft_init(t_my_struct *new);
char			*ft_parser(char *ptr, va_list list, t_my_struct *new);
char			*ft_parse_type(char *ptr, va_list list, t_my_struct *new);
char			*ft_parse_fl(char *ptr, t_my_struct *new);
char			*ft_parse_width(char *ptr, va_list list, t_my_struct *new);
char			*ft_parse_perc(char *ptr, va_list list, t_my_struct *new);
char			*ft_p_s(char *ptr, t_my_struct *new, va_list list);
char			*ft_p_c(char *ptr, t_my_struct *new, va_list list);
char			*ft_p_d_i_u(char *ptr, t_my_struct *new, va_list list);
char			*ft_itoa_uns(unsigned int n);
char			*ft_itoa(int n);
int				ft_count(int n);
int				ft_count_uns(unsigned int n);
char			*ft_strdup(char *src);
char			*ft_p_p(char *ptr, va_list list, t_my_struct *new);
char			*ft_p_x(char *ptr, t_my_struct *new, va_list list);
void			work_flags(char *str, t_my_struct *new);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_putstr_fd(char *s, int fd);
void			ft_work_flags_di(char *str, t_my_struct *new);
void			ft_work_flags_u(t_my_struct *new, char *str_2);
void			print_n(t_my_struct *new, int len_n);
char			*itoa_b(unsigned long num, t_my_struct *new);
void			ft_work_flags_p(char *s, t_my_struct *new);
char			*ft_parse_type_two(char *ptr, va_list list, t_my_struct *new);
void			work_fl_u_x(char *str, t_my_struct *new);
void			print_nul(char *str, int len, t_my_struct *new);
void			print_space(t_my_struct *new);
void			print_left(char *str, int len, t_my_struct *new);
void			print_right(char *str, int len, t_my_struct *new);
void			if_nul_fl(char *str, t_my_struct *new, int len);

#endif
