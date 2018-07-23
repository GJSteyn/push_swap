/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 08:14:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/23 15:51:50 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void			do_op(t_s_hold *stacks, char *op)
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
		ft_error("Error\n");
}

static void		get_ops(t_s_hold *st)
{
	char		*in;

	while (get_next_line(0, &in) > 0)
	{
		if (is_op(in))
			lst_append(&st->ops, ft_lstnew(in, ft_strlen(in)));
		else
			ft_error("Error\n");
		ft_strdel(&in);
	}
}

static void		start_curses(void)
{
	initscr();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_YELLOW);
	init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	noecho();
	curs_set(0);
}

static void		run_visualizer(t_s_hold *st)
{
	t_list		*tmp;

	get_ops(st);
	start_curses();
	tmp = st->ops;
	while (tmp)
	{
		do_op(st, (char*)tmp->content);
		visualize(st);
		tmp = tmp->next;
	}
	usleep(2000000);
	endwin();
}

void			run_instructions(t_s_hold *st)
{
	char		*in;

	if (has_usage_op(st->options))
		print_usage();
	if (has_debug_op(st->options))
		print_init(st);
	if (has_vis_op(st->options) && !has_debug_op(st->options))
		run_visualizer(st);
	else
	{
		while (get_next_line(0, &in) > 0)
		{
			do_op(st, in);
			if (has_debug_op(st->options))
				debugger(st, in);
		}
	}
}
