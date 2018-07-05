# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/05 13:32:22 by gsteyn            #+#    #+#              #
#    Updated: 2018/07/05 13:52:29 by gsteyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker
FILES = push_swap.c checker.c check_args.c get_args.c list_ops.c \
		list_ops2.c
SRCS = $(patsubst %.c, srcs/%.c, $(FILES))
OBJS = $(patsubst %.c, bin/%.o, $(FILES)) ./bin/get_next_line.o
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I libft -I gnl -I includes
LIBS = libft/libft.a
GNL = gnl/get_next_line.c

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS) libs gnl
	gcc -o $(NAME1) $(FLAGS) $(OBJS) -L. $(LIBS)

$(NAME2): $(OBJS) libs gnl
	gcc -o $(NAME2) $(FLAGS) $(OBJS) -L. $(LIBS)

libs:
	make -C ./libft fclean && make -C ./libft

gnl:
	gcc -c $(FLAGS) $(INCLUDES) -o ./bin/get_next_line.o $(GNL)

$(OBJS):
	gcc -c $(INCLUDES) $(FLAGS) $(SRCS)
	mv *.o ./bin

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
