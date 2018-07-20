/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:30:02 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/20 08:03:22 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA(c) ft_strcmp(c, "sa") == 0 ? 1 : 0
# define SB(c) ft_strcmp(c, "sb") == 0 ? 1 : 0
# define SS(c) ft_strcmp(c, "ss") == 0 ? 1 : 0
# define PA(c) ft_strcmp(c, "pa") == 0 ? 1 : 0
# define PB(c) ft_strcmp(c, "pb") == 0 ? 1 : 0
# define RA(c) ft_strcmp(c, "ra") == 0 ? 1 : 0
# define RB(c) ft_strcmp(c, "rb") == 0 ? 1 : 0
# define RR(c) ft_strcmp(c, "rr") == 0 ? 1 : 0
# define RRA(c) ft_strcmp(c, "rra") == 0 ? 1 : 0
# define RRB(c) ft_strcmp(c, "rrb") == 0 ? 1 : 0
# define RRR(c) ft_strcmp(c, "rrr") == 0 ? 1 : 0

# define GCLR "\x1B[0m"
# define GRED "\x1B[31m"
# define GGRN "\x1B[32m"
# define GYEL "\x1B[33m"

# include "libft.h"
# include "get_next_line.h"
# include "checker.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <ncurses.h>

typedef struct			s_s_hold
{
	t_list				*args;
	t_list				*stack_a;
	t_list				*stack_b;
	t_list				*ops;
	unsigned int			options;
}						t_s_hold;

void					lst_swap(t_list **lst);
t_list					*lst_pop(t_list **lst);
void					lst_push(t_list **dst, t_list **src);
void					lst_rotate(t_list **lst);
void					lst_rev_rotate(t_list **lst);
void					lst_append(t_list **dst, t_list *ins);
void					lst_insert(t_list *dst, t_list *ins);
int						get_last(t_list *lst);
int						get_first(t_list *lst);
int						get_second(t_list *lst);
void					lst_rem_next(t_list *lst);

t_list					*get_args(int arc, char **arv);
t_list					*get_sorted_args(t_list *args);

void					do_op(t_s_hold *stacks, char *op);

void					swap_a(t_s_hold *stacks);
void					swap_b(t_s_hold *stacks);
void					swap_both(t_s_hold *stacks);
void					push_a(t_s_hold *stacks);
void					push_b(t_s_hold *stacks);
void					rotate_a(t_s_hold *stacks);
void					rotate_b(t_s_hold *stacks);
void					rotate_both(t_s_hold *stacks);
void					rev_rotate_a(t_s_hold *stacks);
void					rev_rotate_b(t_s_hold *stacks);
void					rev_rotate_both(t_s_hold *stacks);

void					push_a_bot(t_s_hold *stacks);
void					push_b_bot(t_s_hold *stacks);
void					b_to_a(t_s_hold *stacks);
void					sort_top_a(t_s_hold *stacks);
void					sort_top_b(t_s_hold *stacks);
void					sort_ends_a(t_s_hold *stacks);
void					sort_ends_b(t_s_hold *stacks);

t_s_hold				*sh_init(t_list *args);

void					debugger(t_s_hold *stacks, char *op);
int					has_debug_op(unsigned int options);
void					print_init(t_s_hold *stacks);

void					sort2(t_s_hold *stacks);
void					sortn(t_s_hold *stacks, int lst1len, int lst2len);
void					push_and_swap(t_s_hold *stacks);

void					sort4(t_s_hold *stacks);

void					normlist(t_list *chaos, t_list *order);

void					reorder(t_s_hold *stacks);

void					simplify(t_list *lst);

void					print_ops(t_list *ops);

void					run_instructions(t_s_hold *stacks);

void					visualize(t_s_hold *stacks);

#endif
