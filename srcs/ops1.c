/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:01:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/21 16:39:49 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_a(t_s_hold *stacks, int checking)
{
	if (ft_lstlen(stacks->stack_a) > 1)
	{
		lst_swap(&(stacks->stack_a));
		if (!checking)
			lst_append(&stacks->ops, ft_lstnew("sa\0", 3));
	}
}

void		swap_b(t_s_hold *stacks, int checking)
{
	if (ft_lstlen(stacks->stack_a) > 1)
	{
		lst_swap(&(stacks->stack_b));
		if (!checking)
			lst_append(&stacks->ops, ft_lstnew("sb\0", 3));
	}
}

void		swap_both(t_s_hold *stacks, int checking)
{
	lst_swap(&(stacks->stack_a));
	lst_swap(&(stacks->stack_b));
	if (!checking)
		lst_append(&stacks->ops, ft_lstnew("ss\0", 3));
}

void		push_a(t_s_hold *stacks, int checking)
{
	if (ft_lstlen(stacks->stack_b) > 0)
	{
		lst_push(&(stacks->stack_a), &(stacks->stack_b));
		if (!checking)
			lst_append(&stacks->ops, ft_lstnew("pa\0", 3));
	}
}

void		push_b(t_s_hold *stacks, int checking)
{
	if (ft_lstlen(stacks->stack_a) > 0)
	{
		lst_push(&(stacks->stack_b), &(stacks->stack_a));
		if (!checking)
			lst_append(&stacks->ops, ft_lstnew("pb\0", 3));
	}
}
