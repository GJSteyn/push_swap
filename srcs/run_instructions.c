/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 08:14:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/10 09:36:55 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

void		do_op(t_s_hold *stacks, char *op)
{
	if (SA(op))
		lst_swap(&(stacks->stack_a));
	else if (SB(op))
		lst_swap(&(stacks->stack_b));
	else if (SS(op))
	{
		lst_swap(&(stacks->stack_a));
		lst_swap(&(stacks->stack_b));
	}
	else if (PA(op))
		lst_push(&(stacks->stack_a), &(stacks->stack_b));
	else if (PB(op))
		lst_push(&(stacks->stack_b), &(stacks->stack_a));
	else if (RA(op))
		lst_rotate(&(stacks->stack_a));
	else if (RB(op))
		lst_rotate(&(stacks->stack_b));
	else if (RR(op))
	{
		lst_rotate(&(stacks->stack_a));
		lst_rotate(&(stacks->stack_b));
	}
	else if (RRA(op))
		lst_rev_rotate(&(stacks->stack_a));
	else if (RRB(op))
		lst_rev_rotate(&(stacks->stack_b));
	else if (RRR(op))
	{
		lst_rev_rotate(&(stacks->stack_a));
		lst_rev_rotate(&(stacks->stack_b));
	}
	else
	{
		ft_putstr_fd("Invalid operation\n", 2);
		exit(1);
	}
}

void		run_instructions(t_s_hold *stacks, int debug)
{
	char		*in;

	while (get_next_line(0, &in) > 0)
	{
		do_op(stacks, in);
		if (debug)
			debugger(stacks);
	}
}
