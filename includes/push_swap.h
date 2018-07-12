/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 11:30:02 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/12 07:27:31 by gsteyn           ###   ########.fr       */
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

# include "libft.h"
# include "get_next_line.h"
# include "checker.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct			s_s_hold
{
	t_list				*stack_a;
	t_list				*stack_b;
}						t_s_hold;

void					lst_swap(t_list **lst);
t_list					*lst_pop(t_list **lst);
void					lst_push(t_list **dst, t_list **src);
void					lst_rotate(t_list **lst);
void					lst_rev_rotate(t_list **lst);
void					lst_append(t_list *dst, t_list *ins);
void					lst_insert(t_list *dst, t_list *ins);

t_list					*get_args(int arc, char **arv);
t_list					*get_sorted_args(int arc, char **arv);

void					run_instructions(t_s_hold *stacks, int debug);
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

void					push_b_bot(t_s_hold *stacks);

t_s_hold				*sh_init(t_list *sa, t_list *sb);

void					debugger(t_s_hold *stacks);

void					push_and_swap(t_s_hold *stacks);

void					normlist(t_list *chaos, t_list *order);

#endif
