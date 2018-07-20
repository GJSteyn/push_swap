/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 08:14:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/20 14:45:36 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void		do_op(t_s_hold *stacks, char *op)
{
	if (SA(op))
		swap_a(stacks, 1);
	else if (SB(op))
		swap_b(stacks, 1);
	else if (SS(op))
		swap_both(stacks, 1);
	else if (PA(op))
		push_a(stacks, 1);
	else if (PB(op))
		push_b(stacks, 1);
	else if (RA(op))
		rotate_a(stacks, 1);
	else if (RB(op))
		rotate_b(stacks, 1);
	else if (RR(op))
		rotate_both(stacks, 1);
	else if (RRA(op))
		rev_rotate_a(stacks, 1);
	else if (RRB(op))
		rev_rotate_b(stacks, 1);
	else if (RRR(op))
		rev_rotate_both(stacks, 1);
	else
		ft_error("Invalid operation\n");
}

static void	get_ops(t_s_hold *st)
{
	char		*in;

	while (get_next_line(0, &in) > 0)
	{
		if (SA(in))
			lst_append(&st->ops, ft_lstnew("sa\0", 3));
		else if (SB(in))
			lst_append(&st->ops, ft_lstnew("sb\0", 3));
		else if (SS(in))
			lst_append(&st->ops, ft_lstnew("ss\0", 3));
		else if (PA(in))
			lst_append(&st->ops, ft_lstnew("pa\0", 3));
		else if (PB(in))
			lst_append(&st->ops, ft_lstnew("pb\0", 3));
		else if (RA(in))
			lst_append(&st->ops, ft_lstnew("ra\0", 3));
		else if (RB(in))
			lst_append(&st->ops, ft_lstnew("rb\0", 3));
		else if (RR(in))
			lst_append(&st->ops, ft_lstnew("rr\0", 3));
		else if (RRA(in))
			lst_append(&st->ops, ft_lstnew("rra\0", 4));
		else if (RRB(in))
			lst_append(&st->ops, ft_lstnew("rrb\0", 4));
		else if (RRR(in))
			lst_append(&st->ops, ft_lstnew("rrr\0", 4));
		else
			ft_error("Invalid operation\n");
	}
}

void		run_instructions(t_s_hold *st)
{
	//char		*in;
	int			debug;
	t_list		*tmp;

	debug = 0;
	if (has_debug_op(st->options))
		debug = 1;
	if (debug)
		print_init(st);
	/*
	while (get_next_line(0, &in) > 0)
	{
		do_op(st, in);
		if (debug)
			debugger(st, in);
		ft_strdel(&in);
	}
	*/
	get_ops(st);
	initscr();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_YELLOW);
	init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	noecho();
	curs_set(0);
	tmp = st->ops;
	while (tmp)
	{
		visualize(st);
		do_op(st, (char*)tmp->content);
		tmp = tmp->next;
	}
	usleep(5000000);
	endwin();
}
