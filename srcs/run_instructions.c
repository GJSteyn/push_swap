/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 08:14:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/19 15:20:34 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void		do_op(t_s_hold *stacks, char *op)
{
	if (SA(op))
		swap_a(stacks);
	else if (SB(op))
		swap_b(stacks);
	else if (SS(op))
		swap_both(stacks);
	else if (PA(op))
		push_a(stacks);
	else if (PB(op))
		push_b(stacks);
	else if (RA(op))
		rotate_a(stacks);
	else if (RB(op))
		rotate_b(stacks);
	else if (RR(op))
		rotate_both(stacks);
	else if (RRA(op))
		rev_rotate_a(stacks);
	else if (RRB(op))
		rev_rotate_b(stacks);
	else if (RRR(op))
		rev_rotate_both(stacks);
	else
		ft_error("Invalid operation\n");
}

void		run_instructions(t_s_hold *stacks)
{
	char		*in;
	int		debug;

	debug = 0;
	if (has_debug_op(stacks->options))
		debug = 1;
	while (get_next_line(0, &in) > 0)
	{
		do_op(stacks, in);
		if (debug)
			debugger(stacks);
	}
}
