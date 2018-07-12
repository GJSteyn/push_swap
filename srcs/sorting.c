/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:22:14 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/12 09:04:03 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_and_swap(t_s_hold *st)
{
	int			top_a;
	int			a_2;
	int			bottom_a;
	int			bottom_b;
	int			top_b;

	top_a = get_first(st->stack_a);
	a_2 = get_second(st->stack_a);
	bottom_a = get_last(st->stack_a);
	top_b = get_first(st->stack_b);
	bottom_b = get_last(st->stack_b);
	if (is_sorted(st->stack_a) && ft_lstlen(st->stack_b) == 0)
		return ;
	else if (top_a > a_2)
	{
		swap_a(st);
		push_and_swap(st);
	}
	else if (bottom_a < top_a)
	{
		rev_rotate_a(st);
		push_and_swap(st);
	}
	else if (top_a < bottom_b)
	{
		push_b(st);
		rotate_b(st);
		push_and_swap(st);
	}
	else if (top_a < top_b)
	{
		rotate_a(st);
		while (get_first(st->stack_b) > top_a)
			push_a(st);
		rev_rotate_a(st);
		push_and_swap(st);
	}
	else if (is_sorted(st->stack_a) && top_a > top_b)
		b_to_a(st);
	else
	{
		push_b(st);
		push_and_swap(st);
	}
}
