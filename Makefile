# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jparejo- <jparejo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 13:14:05 by jparejo-          #+#    #+#              #
#    Updated: 2021/11/25 19:52:14 by jparejo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	ft_printf.c ft_putchar_fd.c ft_putnbr_fd.c print_s.c \
					print_x.c print_d.c print_u.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= 
NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS)
				ar rcs $(NAME) $(OBJS)
				
.PHONY:			all clean fclean re
