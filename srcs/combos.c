/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 06:34:44 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/13 07:01:31 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Push b bottom:
** Push the top value of a to the bottom of b.
*/

void		push_b_bot(t_s_hold *stacks)
{
	push_b(stacks);
	if (ft_lstlen(stacks->stack_b) > 1)
		rotate_b(stacks);
}

/*
** B to A:
** Push all elements from b to a.
*/

void		b_to_a(t_s_hold *st)
{
	while (st->stack_b)
		push_a(st);
}
