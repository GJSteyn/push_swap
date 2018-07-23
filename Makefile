# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/05 13:32:22 by gsteyn            #+#    #+#              #
#    Updated: 2018/07/23 15:52:57 by gsteyn           ###   ########.fr        #
#    Updated: 2018/07/12 08:01:15 by gsteyn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 	= push_swap
NAME2 	= checker
FILES 	= check_args.c get_args.c list_ops.c list_ops2.c \
		is_sorted.c has_duplicates.c run_instructions.c \
		stack_hold_init.c debug.c ops1.c ops2.c ops3.c sorting.c \
		normalize.c combos.c combos2.c merge.c print_ops.c \
		visualizer.c options.c destroy_stack_holder.c print_usage.c
SDIR 	= srcs
ODIR 	= bin
SRCS 	=  $(patsubst %.c, srcs/%.c, $(FILES))
OBJS 	= $(patsubst %.c, bin/%.o, $(FILES)) ./bin/get_next_line.o
FLAGS 	= -Wall -Wextra -Werror
LDFLAGS = -lncurses
INCLUDES = -I libft -I gnl -I includes
LIBS 	= libft/libft.a
GNL 	= gnl/get_next_line.c

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS) libs gnl
	gcc -o $(NAME1) $(FLAGS) $(INCLUDES) $(OBJS) srcs/push_swap.c -L. $(LIBS)

$(NAME2): $(OBJS) libs gnl
	gcc -o $(NAME2) $(FLAGS) $(INCLUDES) $(OBJS) srcs/checker.c -L. $(LIBS)

ps: $(OBJS)
	gcc -o $(NAME1) $(FLAGS) $(LDFLAGS) $(INCLUDES) $(OBJS) srcs/push_swap.c -L. $(LIBS)

check: $(OBJS)
	gcc -o $(NAME2) $(FLAGS) $(LDFLAGS) $(INCLUDES) $(OBJS) srcs/checker.c -L. $(LIBS)

libs:
	make -C ./libft fclean && make -C ./libft

gnl:
	gcc -c $(FLAGS) $(INCLUDES) -o ./bin/get_next_line.o $(GNL)

$(ODIR)/%.o: $(SDIR)/%.c
	gcc -c $(INCLUDES) $(FLAGS) -o $@ $<


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: fclean all
