LIBSRC = ft_printf.c ft_init.c ft_parse_types.c ft_print_d_i_u_p.c ft_print_x.c ft_print_s_c.c \
ft_printf_utils.c ft_itoa.c work_fl_str.c ft_parser.c work_fl_u_x.c\
ft_itoa_u.c work_fl_ptr.c print_n.c work_fl_int.c ft_printf_utils_two.c \

NAME = libftprintf.a

CC = gcc

LIBOBJS	= ${LIBSRC:.c=.o}

CFLAGS	= -Wall -Werror -Wextra

%.o: %.c
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(LIBOBJS)
		ar rc $(NAME) $(LIBOBJS)
		ranlib $(NAME)

clean:
		rm -f *.o
fclean: clean
		rm -f $(NAME)

re: fclean all
