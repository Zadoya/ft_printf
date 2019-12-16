# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dorphan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 17:52:39 by dorphan           #+#    #+#              #
#    Updated: 2019/11/09 17:56:08 by dorphan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libftprintf.a

SRC =	colours.c\
		divide_m.c\
		addition_to_divide_m.c\
		division.c\
		exponent_to_str.c\
		find_function.c\
		formated.c\
		formated_second.c\
 		ft_printf.c\
		mod_b.c\
		mod_c.c\
		mod_f.c\
		mod_file.c\
		mod_id.c\
		mod_o.c\
		mod_p.c\
		mod_s.c\
		mod_ss.c\
		mod_u.c\
		mod_x.c\
		multiplication_m_by_e.c\
		print_b.c\
		print_float.c\
		print_id.c\
		print_u.c\
		print_x.c\
		rounding.c

CC = gcc

FLAGS = -Wall -Wextra -Werror -I. -c

OBJ = $(SRC:.c=.o)

LIBFT = libft/

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			ar rc $(NAME) $(OBJ) libft/*.o
			ranlib $(NAME)

%.o: 		%.c -I
			$(CC) -o $@ $(FLAGS) $<

clean:
			rm -f $(OBJ)
			make -C $(LIBFT) clean

fclean: 	clean
			rm -f $(NAME)
			make -C $(LIBFT) fclean

re: 		fclean all
