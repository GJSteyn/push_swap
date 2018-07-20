/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 11:12:36 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/20 09:16:32 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rev_rotate_both(t_s_hold *stacks, int checking)
{
	lst_rev_rotate(&(stacks->stack_a));
	lst_rev_rotate(&(stacks->stack_b));
	if (!checking)
		lst_append(&stacks->ops, ft_lstnew("rrr\0", 4));
	//ft_putstr_fd("rrr\n", 1);
}
