/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 06:34:44 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/21 17:14:21 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Push a bottom:
** Push the top value of b to the bottom of a.
*/

void		push_a_bot(t_s_hold *stacks, int checking)
{
	push_a(stacks, checking);
	if (ft_lstlen(stacks->stack_a) > 1)
		rotate_a(stacks, checking);
}

/*
** Push b bottom:
** Push the top value of a to the bottom of b.
*/

void		push_b_bot(t_s_hold *stacks, int checking)
{
	push_b(stacks, checking);
	if (ft_lstlen(stacks->stack_b) > 1)
		rotate_b(stacks, checking);
}

/*
** B to A:
** Push all elements from b to a.
*/

void		b_to_a(t_s_hold *st, int checking)
{
	while (st->stack_b)
		push_a(st, checking);
}

/*
** Sort top a:
** Order the top two elements in a ascending.
*/

void		sort_top_a(t_s_hold *st, int checking)
{
	t_list		*lst;

	lst = st->stack_a;
	if (ft_lstlen(lst) < 2)
		return ;
	if (get_first(lst) > get_second(lst))
		rotate_a(st, checking);
}

/*
** Sort top b:
** Order the top two elements in b ascending.
*/

void		sort_top_b(t_s_hold *st, int checking)
{
	t_list		*lst;

	lst = st->stack_b;
	if (ft_lstlen(lst) < 2)
		return ;
	if (get_first(lst) > get_second(lst))
		rotate_b(st, checking);
}
