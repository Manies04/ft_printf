# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:38:11 by tiade-al          #+#    #+#              #
#    Updated: 2024/04/29 15:28:06 by tiade-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Program = libftprintf.a

files = ft_aux.c\
		ft_printf.c\

Compiler = cc

CmpFlags = -Wall -Wextra -Werror

OFILES = $(files:.c=.o)

NAME = $(Program)

$(NAME): $(OFILES)
	$(Compiler) $(CmpFlags) -c $(files) -I./
	ar -rc $(Program) $(OFILES)

all: $(NAME)

clean:
	rm -f $(NAME)
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re