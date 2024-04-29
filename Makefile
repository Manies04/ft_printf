# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:38:11 by tiade-al          #+#    #+#              #
#    Updated: 2024/04/28 23:42:46 by tiade-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Program = libftprintf.a

files = ft_aux.c\
		ft_printf.c\

bonus = 

Compiler = cc

CmpFlags = -Wall -Wextra -Werror

OFILES = $(files:.c=.o)

OBONUS = $(bonus:.c=.o)

NAME = $(Program)

$(NAME): $(OFILES) $(OBONUS)
	$(Compiler) $(CmpFlags) -c $(files) $(bonus) -I./
	ar -rc $(Program) $(OFILES) $(OBONUS)

all: $(NAME)

bonus: $(OBONUS) $(BONUS)
	ar -rc $(NAME) $(OBONUS) $(BONUS)

clean:
	rm -f $(NAME)
	rm -f $(OFILES) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re