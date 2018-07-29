/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rate_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:41:01 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/29 20:26:57 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	get_max(t_list *stack)
{
	int		max;

	max = 0;
	while (stack)
	{
		if (*(int*)stack->content > max)
			max = *(int*)stack->content;
		stack = stack->next;
	}
	return (max);
}

static int	get_best_rotate(t_s_hold *st, int a_len, int curr)
{
	int			best_dir;
	int			best_result;
	int			count;
	int			heuristic;
	int			save;
	int			max;

	best_result = INT_MAX;
	max = get_max(st->stack_a);
	save = INT_MAX;
	count = curr;
	while (count <= max)
	{
		best_dir = get_closest_dir2(st->stack_a, count, a_len);
		heuristic = ft_abs(best_dir) + ft_abs(curr - count);
		if (heuristic < save)
		{
			best_result = best_dir;
			save = heuristic;
		}
		count++;
	}
	return (best_result);
}

static int	has_val(t_list *stack, int curr)
{
	while (stack)
	{
		if (*(int*)stack->content == curr)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void		rate_rotate(t_s_hold *st)
{
	int			best_rotate;
	int			a_len;
	int			s_len;
	int			curr;

	a_len = ft_lstlen(st->stack_a);
	s_len = a_len;
	curr = 1;
	while (a_len > 0)
	{
		best_rotate = get_best_rotate(st, a_len, curr);
		if (best_rotate > 0)
			while (best_rotate-- > 0)
				rotate_a(st, 0);
		else if (best_rotate < 0)
			while (best_rotate++ < 0)
				rev_rotate_a(st, 0);
		push_b(st, 0);
		while (has_val(st->stack_b, curr))
			curr++;
		a_len--;
	}
	put_back(st, s_len);
}
