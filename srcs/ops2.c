/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:08:20 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/11 17:48:04 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate_a(t_s_hold *stacks)
{
	lst_rotate(&(stacks->stack_a));
	ft_putstr_fd("ra\n", 1);
}

void		rotate_b(t_s_hold *stacks)
{
	lst_rotate(&(stacks->stack_b));
	ft_putstr_fd("rb\n", 1);
}

void		rotate_both(t_s_hold *stacks)
{
	lst_rotate(&(stacks->stack_a));
	lst_rotate(&(stacks->stack_b));
	ft_putstr_fd("rr\n", 1);
}

void		rev_rotate_a(t_s_hold *stacks)
{
	lst_rev_rotate(&(stacks->stack_a));
	ft_putstr_fd("rra\n", 1);
}

void		rev_rotate_b(t_s_hold *stacks)
{
	lst_rev_rotate(&(stacks->stack_b));
	ft_putstr_fd("rrb\n", 1);
}
