/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stack_holder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:03:01 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/21 18:31:56 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		destroy_stacks(t_s_hold **st)
{
	ft_lstdel(&(*st)->stack_a, &ft_lstdelcontent);
	ft_lstdel(&(*st)->stack_a, &ft_lstdelcontent);
	ft_lstdel(&(*st)->stack_b, &ft_lstdelcontent);
	ft_lstdel(&(*st)->ops, &ft_lstdelcontent);
	if (st)
		ft_memdel((void**)st);
	st = NULL;
}
