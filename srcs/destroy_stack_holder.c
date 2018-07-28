/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stack_holder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <gsteyn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:03:01 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/28 16:11:02 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_stack(t_list **stack)
{
	t_list			*tmp;
	void			*item;

	tmp = (*stack)->next;
	while (*stack)
	{
		item = (*stack)->content;
		ft_memdel(&item);
		ft_memdel((void**)stack);
		*stack = tmp;
		if (tmp)
			tmp = tmp->next;
	}
}

void	destroy_stacks(t_s_hold **st)
{
	t_list			*args;
	t_list			*stack_a;
	t_list			*stack_b;
	t_list			*ops;

	args = (*st)->args;
	stack_a = (*st)->stack_a;
	stack_b = (*st)->stack_b;
	ops = (*st)->ops;
	if (args)
		destroy_stack(&args);
	if (stack_a)
		destroy_stack(&stack_a);
	if (stack_b)
		destroy_stack(&stack_b);
	if (ops)
		destroy_stack(&ops);
	ft_memdel((void**)st);
}
