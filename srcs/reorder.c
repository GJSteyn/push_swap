/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 07:57:53 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/12 16:00:57 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		reorder(t_s_hold *st)
{
	int		i;
	int		len;
	int		half;

	i = 0;
	len = ft_lstlen(st->stack_a);
	half = len / 2;
	while (i < half)
	{
		if (get_first(st->stack_a) <= half)
		{
			push_b(st);
			i++;
		}
		else
			rotate_a(st);
	}
	b_to_a(st);
}
