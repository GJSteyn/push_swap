/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:22:14 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/11 12:49:49 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_last(t_list *lst)
{
	int		ret;
	t_list	*tmp;

	ret = 0;
	tmp = lst;
	if (lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		ret = *(int*)tmp->content;
	}
	return (ret);
}

static int	get_first(t_list *lst)
{
	int		ret;

	ret = 0;
	if (lst)
		ret = *(int*)lst->content;
	return (ret);
}

static int	get_second(t_list *lst)
{
	int		ret;

	ret = 0;
	if (lst)
	{
		if (lst->next)
		{
			ret = *(int*)lst->next->content;
		}
	}
	return (ret);
}

static void	b_to_a(t_s_hold *st)
{
	while (st->stack_b)
		push_a(st);
}

void		push_and_swap(t_s_hold *st)
{
	int			top_a;
	int			a_2;
	int			bottom_a;
	int			top_b;
	int			b_2;
	int			bottom_b;

	while (!is_sorted(st->stack_a) || ft_lstlen(st->stack_b) > 0)
	{
		top_a = get_first(st->stack_a);
		a_2 = get_second(st->stack_a);
		bottom_a = get_last(st->stack_a);
		top_b = get_first(st->stack_b);
		b_2 = get_second(st->stack_b);
		bottom_b = get_last(st->stack_b);

		if (top_a > bottom_a && top_a > top_b)
			rotate_a(st);
		else if (top_a < bottom_a && top_a > top_b)
			push_b(st);
		else if (top_a < bottom_b)
			push_b_bot(st);
		else if (top_a > a_2)
			swap_a(st);
		else if (ft_lstlen(st->stack_a) == 0)
			b_to_a(st);
	}
}
