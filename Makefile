# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-kouc <mel-kouc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 14:51:37 by mel-kouc          #+#    #+#              #
#    Updated: 2023/05/10 18:38:39 by mel-kouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

SRC = Man/main.c Man/util.c Man/time_util.c Man/init_args.c Man/check_arg.c Man/create.c Man/habitual.c Man/free_all.c

OSRC = $(SRC:.c=.o)

CC = cc

CFLAGS =   -Wall -Wextra -Werror 
#  -g -fsanitize=thread


all: $(NAME)

$(NAME) : $(OSRC)
	@$(CC) $(CFLAGS) $(OSRC) -o $(NAME)
	@echo "*** {Compaling Mandatory ...} ***"

%.o: %.c Man/philosophers.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "*** {Compaling Files ...} ***"

clean :
	@rm -rf $(OSRC)
	@echo "*** {remove objects files ...} ***"
fclean : clean
	@rm -rf $(NAME)
	@echo "*** {remove executable files and clean all files...} ***"

re : fclean all