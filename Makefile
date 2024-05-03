# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:38:11 by tiade-al          #+#    #+#              #
#    Updated: 2024/04/30 22:31:33 by tiade-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_aux.c ft_printf.c

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror 

NAME			= libftprintf.a

all:			$(NAME)
$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME) 

.PHONY:			all clean fclean re bonus