/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 09:28:53 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/19 15:17:08 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void		debugger(t_s_hold *stacks)
{
	t_list		*a;
	t_list		*b;

	if (!stacks)
		return ;
	a = stacks->stack_a;
	b = stacks->stack_b;
	while (a != NULL || b != NULL)
	{
		if (a)
		{
			ft_putnbr_fd(*(int*)a->content, 1);
			a = a->next;
		}
		ft_putchar_fd('\t', 1);
		if (b)
		{
			ft_putnbr_fd(*(int*)b->content, 1);
			b = b->next;
		}
		ft_putchar_fd('\n', 1);
	}
	ft_putstr_fd("_\t_\n", 1);
	ft_putstr_fd("a\tb\n", 1);
}

int		has_debug_op(unsigned int options)
{
	if (ft_2pow('v' - 'a') & options)
		return (1);
	return (0);
}
