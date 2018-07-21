/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:22:14 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/21 17:55:49 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort2(t_s_hold *st)
{
	int		i;
	int		len;

	i = 0;
	len = ft_lstlen(st->stack_a);
	while (i < len / 2)
	{
		if (get_first(st->stack_a) > get_second(st->stack_a))
			swap_a(st, 0);
		rotate_a(st, 0);
		rotate_a(st, 0);
		i++;
	}
}

void		push_and_swap(t_s_hold *st)
{
	int			store;

	while (!is_sorted(st->stack_a) || ft_lstlen(st->stack_b) != 0)
	{
		if (get_first(st->stack_a) > get_second(st->stack_a))
			swap_a(st, 0);
		else if (get_first(st->stack_a) > get_last(st->stack_a))
			rev_rotate_a(st, 0);
		else if (get_first(st->stack_a) < get_last(st->stack_b))
			push_b_bot(st, 0);
		else if (get_first(st->stack_a) < get_first(st->stack_b))
		{
			store = get_first(st->stack_a);
			rotate_a(st, 0);
			while (get_first(st->stack_b) > store)
				push_a(st, 0);
			rev_rotate_a(st, 0);
		}
		else if (is_sorted(st->stack_a) &&
				get_first(st->stack_a) > get_first(st->stack_b))
			b_to_a(st, 0);
		else
			push_b(st, 0);
	}
}
