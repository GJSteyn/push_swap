/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:12:36 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/10 11:12:54 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rev_rotate_both(t_s_hold *stacks)
{
	lst_rev_rotate(&(stacks->stack_a));
	lst_rev_rotate(&(stacks->stack_b));
	ft_putstr_fd("rrr\n", 0);
}
