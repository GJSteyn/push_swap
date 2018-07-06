# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/05 13:32:22 by gsteyn            #+#    #+#              #
#    Updated: 2018/07/06 09:52:39 by gsteyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker
FILES = push_swap.c checker.c check_args.c get_args.c list_ops.c \
		list_ops2.c
SRCS1 = $(patsubst checker.c, , $(patsubst %.c, srcs/%.c, $(FILES)))
SRCS2 = $(patsubst push_swap.c, "", $(patsubst %.c, srcs/%.c, $(FILES)))
OBJS1 = $(patsubst checker.c, "", $(patsubst %.c, bin/%.o, $(FILES))) ./bin/get_next_line.o
OBJS2 = $(patsubst push_swap.c, , $(patsubst %.c, bin/%.o, $(FILES))) ./bin/get_next_line.o
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I libft -I gnl -I includes
LIBS = libft/libft.a
GNL = gnl/get_next_line.c

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS1) libs gnl
	gcc -o $(NAME1) $(FLAGS) $(OBJS1) -L. $(LIBS)

$(NAME2): $(OBJS2) libs gnl
	gcc -o $(NAME2) $(FLAGS) $(OBJS2) -L. $(LIBS)

libs:
	make -C ./libft fclean && make -C ./libft

gnl:
	gcc -c $(FLAGS) $(INCLUDES) -o ./bin/get_next_line.o $(GNL)

$(OBJS1):
	gcc -c $(INCLUDES) $(FLAGS) $(SRCS1)
	mv *.o ./bin

$(OBJS2):
	gcc -c $(INCLUDES) $(FLAGS) $(SRCS2)
	mv *.o ./bin

clean:
	rm -rf $(OBJS1) $(OBJS2)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: fclean all
