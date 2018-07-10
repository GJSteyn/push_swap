/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:01:06 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/10 11:08:08 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_a(t_s_hold *stacks)
{
	lst_swap(&(stacks->stack_a));
	ft_putstr_fd("sa\n", 0);
}

void		swap_b(t_s_hold *stacks)
{
	lst_swap(&(stacks->stack_b));
	ft_putstr_fd("sb\n", 0);
}

void		swap_both(t_s_hold *stacks)
{
	lst_swap(&(stacks->stack_a));
	lst_swap(&(stacks->stack_b));
	ft_putstr_fd("ss\n", 0);
}

void		push_a(t_s_hold *stacks)
{
		lst_push(&(stacks->stack_a), &(stacks->stack_b));
		ft_putstr_fd("pa\n", 0);
}

void		push_b(t_s_hold *stacks)
{
		lst_push(&(stacks->stack_b), &(stacks->stack_a));
		ft_putstr_fd("pb\n", 0);
}
