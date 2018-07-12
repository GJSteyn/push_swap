/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:08:20 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/12 19:09:20 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate_a(t_s_hold *stacks)
{
	lst_rotate(&(stacks->stack_a));
	lst_append(&stacks->ops, ft_lstnew("ra\0", 3));
	//ft_putstr_fd("ra\n", 1);
}

void		rotate_b(t_s_hold *stacks)
{
	lst_rotate(&(stacks->stack_b));
	lst_append(&stacks->ops, ft_lstnew("rb\0", 3));
	//ft_putstr_fd("rb\n", 1);
}

void		rotate_both(t_s_hold *stacks)
{
	lst_rotate(&(stacks->stack_a));
	lst_rotate(&(stacks->stack_b));
	lst_append(&stacks->ops, ft_lstnew("rr\0", 3));
	//ft_putstr_fd("rr\n", 1);
}

void		rev_rotate_a(t_s_hold *stacks)
{
	lst_rev_rotate(&(stacks->stack_a));
	lst_append(&stacks->ops, ft_lstnew("rra\0", 4));
	//ft_putstr_fd("rra\n", 1);
}

void		rev_rotate_b(t_s_hold *stacks)
{
	lst_rev_rotate(&(stacks->stack_b));
	lst_append(&stacks->ops, ft_lstnew("rrb\0", 4));
	//ft_putstr_fd("rrb\n", 1);
}
