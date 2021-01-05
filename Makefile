# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jzeybel <jzeybel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 13:48:57 by jzeybel           #+#    #+#              #
#    Updated: 2021/01/05 17:30:41 by jzeybel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

CC = gcc

CFLAGS = -Wextra -Werror -Wall

BUF = 32

BUF_FLAGS = -D BUFFER_SIZE=$(BUF)

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

MAIN = ../main.c

$(NAME) : $(OBJ)
	 $(CC) $(CFLAGS) $(BUF_FLAGS) -o $@ $(OBJ) $(MAIN)

all : $(NAME)

debug : CFLAGS += -g -fsanitize=address
debug : $(NAME)


.c.o :
	$(CC) $(CFLAGS) $(BUF_FLAGS) -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

redebug : fclean debug

.PHONY : all debug clean fclean re redebug
