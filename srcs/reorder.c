/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 07:57:53 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/12 19:25:01 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		reorder(t_s_hold *st)
{
	int		i;
	int		len;
	int		half;
	int		pos1;
	int		pos2;
	int		diff;
	int		first;

	i = 0;
	len = ft_lstlen(st->stack_a);
	half = len / 2;
	pos1 = len / 4;
	pos2 = len / 4 * 3;
	diff = pos1 - pos2;
	while (i < diff)
	{
		first = get_first(st->stack_a);
		if (first < half && first > pos1)
		{
			push_b_bot(st);
			i++;
		}
		else if (first >= half && first < pos2)
		{
			push_b(st);
			i++;
		}
		else
			rotate_a(st);
	}
	i = 0;
	while (i < pos1)
	{
		first = get_first(st->stack_a);
		if (first <= pos1)
		{
			push_b_bot(st);
			i++;
		}
		else
			rotate_a(st);
	}
	b_to_a(st);
	// to do: also sort while reordering
}
